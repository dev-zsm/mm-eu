#!/usr/bin/env python3
"""Try the m2c draft of every unmatched function as-is, compiled with a few IDO flag sets; keep exact matches.
Run in WSL (venv, MM_CC set).  usage: auto_match.py <seg> <max_size_hex> [jobs=3]
Matches go to build/auto_match/<seg>/<fn>.c (not src/): review them, move to src/<seg>/, then run verify_all.sh.
Log: build/auto_match/<seg>.txt (resume-safe: functions already tried are skipped)."""
import re, subprocess, sys, tempfile
from multiprocessing import Pool
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import match  # noqa: E402

M2C = ROOT / "tools/vendor/m2c/m2c.py"
FLAG_SETS = (["-O2", "-g3", "-mips2"], ["-O2", "-g0", "-mips2"], ["-O1", "-g0", "-mips2"], ["-O1", "-g3", "-mips2"])
BASE = match.DEFAULT_FLAGS[3:] + ["-I" + str(ROOT / "tools/vendor/m2c")]


def same(want: bytes, cfile: Path, fn: str, flags: list) -> bool:
    try:
        got, masks = match.compiled(cfile, fn, flags + BASE, len(want))
    except Exception:  # does not compile, or the symbol is missing
        return False
    if len(got) > len(want) and not any(got[len(want):]):
        got = got[:len(want)]
    return len(got) == len(want) and match.mask(want, masks) == match.mask(got, masks)


def attempt(job):
    seg, fn, want, asm = job
    with tempfile.TemporaryDirectory() as d:
        s = Path(d) / f"{fn}.s"
        s.write_text(asm)
        r = subprocess.run([sys.executable, str(M2C), "-t", "mips-ido-c", "--valid-syntax", str(s)],
                           capture_output=True, text=True)
        if r.returncode or "M2C_ERROR" in r.stdout or f" {fn}(" not in r.stdout:
            return fn, "m2c failed", None
        src = '#include "types.h"\n#include "m2c_macros.h"\n\n' + r.stdout
        c = Path(d) / f"{fn}.c"
        c.write_text(src)
        for flags in FLAG_SETS:
            if same(want, c, fn, flags):
                return fn, "MATCH " + " ".join(flags), f"// FLAGS: {' '.join(flags)}\n" + src
    return fn, "no match", None


def main():
    seg, max_size = sys.argv[1], int(sys.argv[2], 16)
    jobs = int(sys.argv[3]) if len(sys.argv) > 3 else 3
    text = (ROOT / "asm" / seg / "text.s").read_text()
    head = text[:text.index("nonmatching ")]
    out = ROOT / "build/auto_match" / seg
    out.mkdir(parents=True, exist_ok=True)
    log = out.parent / f"{seg}.txt"
    done = {l.split()[0] for l in log.read_text().splitlines()} if log.exists() else set()
    asm_only = ROOT / "config" / f"{seg}.asm_only.txt"
    skip = set(asm_only.read_text().split()) if asm_only.exists() else set()
    path, base = match.SEG[seg]
    rom = path.read_bytes()
    todo = []
    for ch in re.split(r"(?=^nonmatching )", text, flags=re.M)[1:]:
        m = re.match(r"nonmatching (\w+), (0x[0-9A-Fa-f]+)", ch)
        if not m:
            continue
        fn, size = m.group(1), int(m.group(2), 16)
        if (size > max_size or not fn.startswith("func_") or fn in done or fn in skip
                or (ROOT / "src" / seg / f"{fn}.c").exists()):
            continue
        off = int(fn[-8:], 16) - base
        todo.append((seg, fn, rom[off:off + size], head + ch))
    print(f"{len(todo)} functions to try", flush=True)
    won = 0
    with Pool(jobs) as pool, log.open("a") as lf:
        for fn, status, src in pool.imap_unordered(attempt, todo):
            if src:
                (out / f"{fn}.c").write_text(src)
                won += 1
            lf.write(f"{fn} {status}\n")
            lf.flush()
    print(f"DONE: {won} matched out of {len(todo)}")


if __name__ == "__main__":
    main()
