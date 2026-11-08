#!/usr/bin/env python3
"""Content-addressed cache of compiled and assembled objects, shared by match.py, verify_src.py and build_seg.py.
A function whose source, flags, compiler and headers did not change is never compiled twice: the object is found in
the cache by the SHA-256 of everything that can change its bytes. Delete ~/.cache/mm-n64-decomp (or run `make clean`) to start from scratch.
Also picks the fastest copy of the compilers: MM_CC / MM_CC53, else ~/ido71 and ~/ido53 (native WSL disk, about four
times faster than the copies in tools/vendor on /mnt/c; `tools/split/setup_wsl.sh` creates them), else tools/vendor."""
import contextlib, hashlib, json, os, re, shutil, subprocess, tempfile, threading, time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
# On the native WSL disk: file operations on /mnt/c cost about 1.5 ms each and dominate the whole check otherwise.
CACHE = Path(os.environ.get("MM_CACHE") or Path.home() / ".cache" / "mm-n64-decomp")
WORK = CACHE / "work"  # per-function objects of build_seg.py, build/<seg>/fn before the cache moved here
JOBS = int(os.environ.get("MM_JOBS") or os.cpu_count() or 4)   # MM_JOBS: fewer workers on a machine that is also used for something else


def _compiler(version: str) -> Path:
    env = os.environ.get("MM_CC53" if version == "53" else "MM_CC")
    native = Path.home() / f"ido{version}" / "cc"
    return Path(env) if env else native if native.exists() else ROOT / f"tools/vendor/ido{version}/cc"


def uses_ido53(cfile: Path) -> bool:
    return any(re.match(r"// COMPILER: ido53\s*$", l) for l in cfile.read_text().splitlines()[:3])


def compiler_for(cfile: Path) -> Path:
    return _compiler("53" if uses_ido53(cfile) else "71")


def directives(text: str) -> str:
    """The `// FLAGS:` and `// COMPILER:` lines of a source, which every rewritten copy of it must keep."""
    return "".join(l + "\n" for l in text.splitlines()[:3] if l.startswith(("// FLAGS:", "// COMPILER:")))


def _headers() -> str:
    h = hashlib.sha256()
    for p in sorted((ROOT / "include").rglob("*")):   # include/generated/overlays/ holds the headers of the overlays
        if p.is_file():
            h.update(p.relative_to(ROOT / "include").as_posix().encode() + p.read_bytes())
    return h.hexdigest()


_HEADERS = None


def headers() -> str:
    """SHA-256 of include/: any change to a header invalidates every cached object."""
    global _HEADERS
    _HEADERS = _HEADERS or _headers()
    return _HEADERS


def digest(*parts: bytes) -> str:
    return _digest(*parts)


def _digest(*parts: bytes) -> str:
    h = hashlib.sha256()
    for p in parts:
        h.update(len(p).to_bytes(8, "big") + p)
    return h.hexdigest()


def compile_obj(cfile: Path, flags: list[str]) -> Path:
    """Path of the cached object for `cfile` compiled with the full `flags` (optimisation flags plus -G 0 ...).
    The object is shared: copy it before modifying it."""
    source = cfile.read_bytes().replace(b"\r\n", b"\n")
    ido = "53" if any(re.match(r"// COMPILER: ido53\s*$", l) for l in source.decode(errors="replace").splitlines()[:3]) else "71"
    # the context header of an imported function can change while a process runs (tools/search/ref_import.py rewrites it between its
    # two passes), and `headers()` is computed once: the header the file includes is part of the key too
    context = b"".join((ROOT / "include" / m).read_bytes() for m in re.findall(r'#include "(generated/mm/[^"]+)"', source.decode(errors="replace"))
                       if (ROOT / "include" / m).exists())
    key = _digest(b"cc" + ido.encode(), " ".join(flags).encode(), source, headers().encode(), context)
    obj = CACHE / "obj" / f"{key}.o"
    if good(obj):
        return obj
    obj.parent.mkdir(parents=True, exist_ok=True)
    with _lock_for(key), GATE():   # one compile per key in this process; GATE() lets a server cap the compilers it runs
        if good(obj):
            return obj
        with tempfile.TemporaryDirectory() as d:  # IDO cc mishandles -o paths containing spaces
            r = subprocess.run([str(_compiler(ido)), "-c", *flags, "-o", d + "/x.o", str(cfile)], capture_output=True, text=True)
            if r.returncode or not (os.path.exists(d + "/x.o") and os.path.getsize(d + "/x.o")):
                if not QUIET:
                    print(r.stderr, end="")
                raise subprocess.CalledProcessError(r.returncode or 1, "cc", stderr=r.stderr)
            tmp = obj.with_suffix(f".{os.getpid()}.{threading.get_ident()}.tmp")
            shutil.move(d + "/x.o", tmp)
            os.replace(tmp, obj)  # atomic: parallel workers may race on the same key
    return obj


def good(obj: Path) -> bool:
    """A cached file that exists and is not empty. An empty one (a run killed or crashed halfway on a filesystem without atomic
    renames, or a full disk) is deleted, so it is compiled again instead of being read as an object."""
    try:
        if obj.stat().st_size:
            return True
        obj.unlink()
    except OSError:
        pass
    return False


def scrub() -> int:
    """Delete the empty files and the leftover temporary files of a killed run from the cache; the number deleted."""
    n = 0
    for p in list(CACHE.glob("*/*.o")) + list(CACHE.glob("*/*.json")) + list(CACHE.glob("*/*.tmp")):
        try:
            if p.suffix == ".tmp" and time.time() - p.stat().st_mtime > 600 or p.stat().st_size == 0:
                p.unlink()
                n += 1
        except OSError:
            pass
    return n


_LOCKS, _LOCKS_GUARD = {}, threading.Lock()
QUIET = False                              # True: a failed compile does not print its messages (they are in the exception)
GATE = contextlib.nullcontext              # replaced by a server: a callable returning a context manager held while cc runs


def _lock_for(key: str) -> threading.Lock:
    with _LOCKS_GUARD:
        return _LOCKS.setdefault(key, threading.Lock())


def info(obj: Path):
    """(sections {name: size}, imported symbols) of a cached object, itself cached next to it (objdump and nm are slow)."""
    side = obj.with_suffix(".json")
    if good(side):
        try:
            d = json.loads(side.read_text())
            return d["secs"], set(d["imported"])
        except (ValueError, KeyError):   # truncated by a crash: computed again
            pass
    run = lambda *a: subprocess.run(a, check=True, capture_output=True, text=True).stdout
    secs = {m.group(1): int(m.group(2), 16) for m in re.finditer(
        r"\s(\.(?:rodata|rdata|data|sdata|bss|sbss|lit4|lit8))\s+([0-9a-f]+)", run("mips-linux-gnu-objdump", "-h", str(obj)))}
    imported = sorted({l.split()[-1] for l in run("mips-linux-gnu-nm", str(obj)).splitlines() if l.split()[:1] == ["U"] or " U " in l})
    tmp = side.with_suffix(f".{os.getpid()}.{threading.get_ident()}.tmp")
    tmp.write_text(json.dumps({"secs": secs, "imported": imported}))
    os.replace(tmp, side)
    return secs, set(imported)


def assemble(text: str, cmd: list[str]) -> Path:
    """Path of the cached object for assembly `text` assembled with `cmd` (the `as` command line without -o)."""
    macro = (ROOT / "include" / "macro.inc").read_bytes()
    key = _digest(b"as", " ".join(cmd).encode(), text.encode(), macro)
    obj = CACHE / "as" / f"{key}.o"
    if good(obj):
        return obj
    obj.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory() as d:
        src = Path(d) / "x.s"
        src.write_text(text)
        subprocess.run([*cmd, str(src), "-o", d + "/x.o"], check=True, capture_output=True, text=True)
        tmp = obj.with_suffix(f".{os.getpid()}.{threading.get_ident()}.tmp")
        shutil.move(d + "/x.o", tmp)
        os.replace(tmp, obj)
    return obj


def warm(jobs):
    """Run zero-argument callables (typically `lambda: compile_obj(...)`) on every core to fill the cache."""
    with ThreadPoolExecutor(JOBS) as ex:
        list(ex.map(lambda f: f(), jobs))
