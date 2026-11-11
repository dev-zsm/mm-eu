#!/usr/bin/env python3
"""The incremental checks must never say green when a full run fails. Run in WSL from the root (`make selfcheck`, or
`tools/check/fastcheck.sh selfcheck` when the repository is on the Windows disk); about a minute.
In a scratch copy of the boot segment, for a clean tree and then for each deliberate breakage (a function, a header reached
through another header, a byte of the ROM segment, two names swapped), compares the verdict of an incremental run (the cache
and the manifests of the runs before it) with the verdict of a full run (MM_FULL=1 on an empty cache).
Exit status is 0 only if both always agree and every breakage that must fail does fail."""
import os, re, shutil, subprocess, sys, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
bad = []

with tempfile.TemporaryDirectory(prefix="mm-selfcheck-", dir=Path.home()) as tmp:   # the native disk
    t = Path(tmp) / "tree"
    skip = shutil.ignore_patterns("wip", "__pycache__", "vendor")
    for d in ("tools", "include", "config", "src/boot", "asm/boot"):
        shutil.copytree(ROOT / d, t / d, ignore=skip)
    (t / "tools/vendor").symlink_to(ROOT / "tools/vendor")
    (t / "build/boot").mkdir(parents=True)
    for f in [ROOT / "build/boot.bin", ROOT / "build/boot/boot.ld", *(ROOT / "build/boot").glob("undefined_*.txt")]:
        shutil.copy(f, t / f.relative_to(ROOT))

    def run(cache, **env):
        r = subprocess.run(["bash", "tools/check/verify_all.sh", "boot"], cwd=t, capture_output=True, text=True,
                           env={**os.environ, "MM_CACHE": f"{tmp}/{cache}", **env})
        return r.returncode == 0

    def case(what, must_fail=True):
        inc = run("inc")
        full = run(f"full-{len(os.listdir(tmp))}", MM_FULL="1")
        ok = inc == full and not (must_fail and full)
        print(f"{'ok  ' if ok else 'BAD '} {what}: incremental {'green' if inc else 'red'}, full {'green' if full else 'red'}", flush=True)
        if not ok:
            bad.append(what)

    def broken(path, change):
        """Apply `change` to the bytes of a file; returns the function that puts it back."""
        old = path.read_bytes()
        path.write_bytes(change(old))
        return lambda: path.write_bytes(old)

    def included(f):
        """The headers of include/ a file names, as paths of the copy."""
        names = re.findall(r'#\s*include\s*["<]([^">]+)[">]', f.read_text(errors="replace"))
        return [p for n in names for p in (f.parent / n, t / "include" / n) if p.is_file()]

    run("inc")   # fills the cache and the manifests; the runs below start from them
    case("clean tree", must_fail=False)
    cfile = next(f for f in sorted((t / "src/boot").rglob("func_*.c")) if any(included(h) for h in included(f)))
    nested = next(n for h in included(cfile) for n in included(h))
    names = t / "config/boot/names.txt"

    def swap(data):
        lines = data.decode().splitlines()
        i, j = [k for k, l in enumerate(lines) if l.startswith("func_")][:2]
        a, b = lines[i].split(), lines[j].split()
        lines[i], lines[j] = f"{a[0]} {b[1]}", f"{b[0]} {a[1]}"
        return ("\n".join(lines) + "\n").encode()

    for what, path, change, must_fail in (
            # a stray brace: IDO's preprocessor lets an #error through
            (f"function broken ({cfile.name})", cfile, lambda d: d + b"\n}\n", True),
            (f"nested header broken ({nested.relative_to(t)})", nested, lambda d: d + b"\n}\n", True),
            ("last byte of the ROM segment flipped", t / "build/boot.bin", lambda d: d[:-1] + bytes([d[-1] ^ 1]), True),
            ("two names swapped", names, swap, False)):
        restore = broken(path, change)
        case(what, must_fail)
        restore()
    case("clean tree again", must_fail=False)

print("selfcheck: " + (f"FAILED ({', '.join(bad)})" if bad else "the incremental and the full run agree everywhere"))
sys.exit(bool(bad))
