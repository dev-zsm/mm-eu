#!/usr/bin/env python3
"""Rank the automatic drafts that compile but do not match yet, so the permuter gets the promising ones first.
Run in WSL (venv, MM_CC set) after auto_match.py.  usage: auto_near.py <seg> [max_diff_ratio=0.25] [jobs=3]
For every function auto_match tried without success: compile its m2c draft with the usual IDO flag sets, keep the
best one if the size is right and at most `ratio` of the instructions differ, and store it as
src/<seg>/wip/<fn>.c (untracked for `code`).  Ranking: build/auto_match/near_<seg>.txt  (closest first)."""
import re, subprocess, sys, tempfile
from multiprocessing import Pool
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import auto_match as am  # noqa: E402
import match  # noqa: E402
import srcpath  # noqa: E402


def ndiff(want: bytes, cfile: Path, fn: str, flags: list):
    try:
        got, masks = match.compiled(cfile, fn, flags + am.BASE, len(want))
    except Exception:
        return None
    if len(got) > len(want) and not any(got[len(want):]):
        got = got[:len(want)]
    if len(got) != len(want):
        return None
    a, b = match.mask(want, masks), match.mask(got, masks)
    return sum(x != y for x, y in zip(a, b)), len(a)


def attempt(job):
    seg, fn, want, asm, ratio = job
    with tempfile.TemporaryDirectory() as d:
        s = Path(d) / f"{fn}.s"
        s.write_text(asm)
        r = subprocess.run([sys.executable, str(am.M2C), "-t", "mips-ido-c", "--valid-syntax", str(s)],
                           capture_output=True, text=True)
        if r.returncode or f" {fn}(" not in r.stdout:
            return fn, None
        src = '#include "types.h"\n#include "m2c_compat.h"\n\n' + r.stdout.replace("void *", "u8 *").replace("M2C_UNK8", "M2C_UNK").replace("M2C_UNK16", "M2C_UNK").replace("M2C_UNK32", "M2C_UNK")
        c = Path(d) / f"{fn}.c"
        c.write_text(src)
        best = None
        for flags in am.FLAG_SETS:
            res = ndiff(want, c, fn, flags)
            if res and (best is None or res[0] < best[0]):
                best = (res[0], res[1], flags)
        if best and 0 < best[0] <= ratio * best[1]:
            return fn, (best[0], best[1], f"// FLAGS: {' '.join(best[2])}\n// STATUS: automatic draft, {best[0]}/{best[1]} instructions differ\n" + src)
    return fn, None


def main():
    seg = sys.argv[1]
    ratio = float(sys.argv[2]) if len(sys.argv) > 2 else 0.25
    jobs = int(sys.argv[3]) if len(sys.argv) > 3 else 3
    log = ROOT / "build/auto_match" / f"{seg}.txt"
    failed = {l.split()[0] for l in log.read_text().splitlines() if l.split()[1] == "no"}
    text = (ROOT / "asm" / seg / "text.s").read_text()
    head = text[:text.index("nonmatching ")]
    path, base = match.SEG[seg]
    rom = path.read_bytes()
    wipdir = ROOT / "src" / seg / "wip"
    wipdir.mkdir(exist_ok=True)
    todo = []
    for ch in re.split(r"(?=^nonmatching )", text, flags=re.M)[1:]:
        m = re.match(r"nonmatching (\w+), (0x[0-9A-Fa-f]+)", ch)
        if m and m.group(1) in failed and not srcpath.path(seg, m.group(1)).exists():
            fn, size = m.group(1), int(m.group(2), 16)
            off = int(fn[-8:], 16) - base
            todo.append((seg, fn, rom[off:off + size], head + ch, ratio))
    print(f"{len(todo)} drafts to rank", flush=True)
    rows = []
    with Pool(jobs) as pool:
        for fn, res in pool.imap_unordered(attempt, todo):
            if res:
                (wipdir / f"{fn}.c").write_text(res[2])
                rows.append((res[0] / res[1], fn, res[0], res[1]))
    rows.sort()
    out = ROOT / "build/auto_match" / f"near_{seg}.txt"
    out.write_text("".join(f"{fn} {d}/{n} instr differ\n" for _, fn, d, n in rows))
    print(f"DONE: {len(rows)} near misses of {len(todo)} -> {out}")


if __name__ == "__main__":
    main()
