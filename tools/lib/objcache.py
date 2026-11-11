#!/usr/bin/env python3
"""Content-addressed cache of compiled and assembled objects, shared by match.py, verify_src.py and build_seg.py.
A function whose source, flags, compiler and reachable headers (`deps`) did not change is never compiled twice: the object is
found in the cache by the SHA-256 of everything that can change its bytes. Delete ~/.cache/mm-n64-decomp (or run `make clean`) to start from scratch.
One cache directory serves every checkout and every process of the machine: an object is written under a temporary name and
renamed, the state of a checkout (verdicts, link objects) lives in its own folder (STATE), and `trim` keeps the whole under
MM_CACHE_MAX GB (default 8) by deleting the least recently used objects. MM_CACHE moves the cache; nobody needs a private one.
Also picks the fastest copy of the compilers: MM_CC / MM_CC53, else ~/ido71 and ~/ido53 (native WSL disk, about four
times faster than the copies in tools/vendor on /mnt/c; `tools/split/setup_wsl.sh` creates them), else tools/vendor."""
import contextlib, hashlib, json, os, re, shutil, subprocess, tempfile, threading, time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
# On the native WSL disk: file operations on /mnt/c cost about 1.5 ms each and dominate the whole check otherwise.
CACHE = Path(os.environ.get("MM_CACHE") or Path.home() / ".cache" / "mm-n64-decomp")
MAX = float(os.environ.get("MM_CACHE_MAX") or 8) * 2 ** 30   # MM_CACHE_MAX: the size of the cache in GB above which `trim` deletes
STATE = CACHE / "tree" / hashlib.sha1(str(ROOT).encode()).hexdigest()[:10]   # what belongs to this checkout alone: two checkouts never write the same file
WORK = STATE / "work"  # per-function objects of build_seg.py, build/<seg>/fn before the cache moved here
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
    """SHA-256 of include/. Only the fallback of `deps`, which hashes just the headers a file can reach."""
    global _HEADERS
    _HEADERS = _HEADERS or _headers()
    return _HEADERS


_INC = re.compile(rb'#[ \t]*include[ \t]*(?:"([^"\n]+)"|<([^>\n]+)>|(\S))')
_HDR = {}     # path -> (SHA-256 of the file, the names it includes), None for a file that does not exist
_REACH = {}   # (path, include folders) -> every path the compiler could open from that header


def _includes(data: bytes) -> list:
    """The names a text includes, None for an `#include MACRO`. Anywhere in the text, comments too: more is safe, fewer is not."""
    return [(a or b).decode(errors="replace") if a or b else None for a, b, _ in _INC.findall(data)]


def _header(p: str):
    # a context header (generated/mm) is rewritten while a process runs (tools/search/ref_import.py): always read again
    if p not in _HDR or "generated/mm/" in p:
        try:
            with open(p, "rb") as f:
                d = f.read()
            _HDR[p] = hashlib.sha256(d).digest(), _includes(d)
        except OSError:
            _HDR[p] = None
    return _HDR[p]


def _candidates(here: str, name, dirs: tuple) -> list:
    if name is None:
        raise LookupError("#include MACRO")
    return [os.path.normpath(os.path.join(d, name)) for d in (here, *dirs)]


def _reach(p: str, dirs: tuple) -> tuple:
    seen, todo = {p}, [p]
    while todo:
        q = todo.pop()
        for name in (_header(q) or (0, ()))[1]:
            for c in _candidates(os.path.dirname(q), name, dirs):
                if c not in seen:
                    seen.add(c)
                    todo.append(c)
    return tuple(seen)


def deps(source: bytes, cfile, flags) -> bytes:
    """Hash of every header `source` (the text of `cfile`) can make the compiler open with `flags`: for each #include, of the
    source or of a header reached from it, the file of that name in the folder of the including file and in every -I folder,
    with its content or the fact that it does not exist. A superset of what the preprocessor reads (it ignores #if), so a
    change to any header a file can see changes its key, and a change to another header does not.
    An `#include MACRO` cannot be followed: the hash of the whole of include/ is used instead."""
    dirs = tuple(os.path.abspath(f[2:]) for f in flags if f.startswith("-I") and len(f) > 2)
    paths = set()
    try:
        for name in _includes(source):
            for p in _candidates(os.path.dirname(os.path.abspath(cfile)), name, dirs):
                if "generated/mm/" in p or (p, dirs) not in _REACH:
                    _REACH[p, dirs] = _reach(p, dirs)
                paths.update(_REACH[p, dirs])
    except LookupError:
        return headers().encode()
    h, root = hashlib.sha256(), str(ROOT) + os.sep
    for p in sorted(paths):
        e = _header(p)
        h.update((p[len(root):] if p.startswith(root) else p).encode() + b"\0" + (e[0] if e else b"-"))
    return h.digest()


def flag_key(flags) -> bytes:
    """The flags as they enter a key: without the place of the checkout, so that a mirror and its repository share objects."""
    return " ".join(flags).replace(str(ROOT), "$ROOT").encode()


_IDENT = {}


def ident(ido: str) -> bytes:
    """What produces an object besides its inputs: this file and the compiler (names, sizes and dates of its files)."""
    if ido not in _IDENT:
        cc = _compiler(ido)
        files = sorted((p.name, p.stat().st_size, p.stat().st_mtime_ns) for p in cc.parent.iterdir() if p.is_file())
        _IDENT[ido] = _digest(Path(__file__).read_bytes(), str(cc).encode(), repr(files).encode()).encode()
    return _IDENT[ido]


FULL = bool(os.environ.get("MM_FULL"))   # MM_FULL=1: the checks trust no earlier verdict and no earlier link (objects stay cached by content)


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
    key = _digest(b"cc" + ido.encode(), flag_key(flags), source, deps(source, cfile, flags), ident(ido))
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
    _stored()
    return obj


def good(obj: Path) -> bool:
    """A cached file that exists and is not empty. An empty one (a run killed or crashed halfway on a filesystem without atomic
    renames, or a full disk) is deleted, so it is compiled again instead of being read as an object."""
    try:
        st = obj.stat()
        if st.st_size:
            if time.time() - st.st_mtime > 600:
                os.utime(obj)   # the date of a cached file is its last use, to ten minutes: what `trim` sorts on
            return True
        obj.unlink()
    except OSError:
        pass
    return False


def trim(force: bool = False) -> int:
    """Keep the cache under MAX: delete the least recently used files down to 80 % of it, and the state of a checkout that
    was not checked for a week; the bytes freed. One scan of the cache every five minutes at most for the whole machine (the
    date of trim.stamp), so the cache can overshoot by what is written in between.
    shortcut: a file used in the last hour is never deleted, which leaves a process the time to read the object it was just
    given; a process that keeps a path for more than an hour without asking again needs a lock instead."""
    stamp, now = CACHE / "trim.stamp", time.time()
    try:
        if not force and now - stamp.stat().st_mtime < 300:
            return 0
    except OSError:
        pass
    CACHE.mkdir(parents=True, exist_ok=True)
    stamp.touch()
    files, freed = [], 0
    for d in CACHE.iterdir():
        if d.is_dir() and d.name != "tree":
            for e in os.scandir(d):
                try:
                    if e.is_file(follow_symlinks=False):
                        st = e.stat()
                        files.append((st.st_mtime, getattr(st, "st_blocks", 0) * 512 or st.st_size, e.path))
                except OSError:
                    pass
        elif d.is_dir():
            for t in d.iterdir():
                try:
                    if now - t.stat().st_mtime > 7 * 86400:
                        shutil.rmtree(t, ignore_errors=True)
                except OSError:
                    pass
    total = sum(f[1] for f in files)
    for mtime, size, path in sorted(files):
        if total - freed <= 0.8 * MAX or now - mtime < 3600:
            break
        try:
            if os.stat(path).st_mtime == mtime:   # not taken by another process since the scan
                os.unlink(path)
                freed += size
        except OSError:
            pass
    return freed


_TRIM = [0.0]


def _stored():
    """After a new file entered the cache: time for a `trim`? (one look at the clock; one stat every five minutes)"""
    if time.time() > _TRIM[0]:
        _TRIM[0] = time.time() + 300
        trim()


def used():
    """This checkout was checked now: `trim` keeps its state (STATE) for a week after the last time."""
    STATE.mkdir(parents=True, exist_ok=True)
    os.utime(STATE)


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
    _stored()
    return obj


def warm(jobs):
    """Run zero-argument callables (typically `lambda: compile_obj(...)`) on every core to fill the cache."""
    with ThreadPoolExecutor(JOBS) as ex:
        list(ex.map(lambda f: f(), jobs))
