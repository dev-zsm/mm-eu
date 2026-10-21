#!/usr/bin/env python3
"""Try many IDO flag combinations on every unmatched function's draft; promote any that matches and report the best
score per function. CPU only. Run in WSL.  usage: flag_sweep.py <seg> [first_n]
Log: build/flag_sweep_<seg>.txt"""
import itertools, re, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import match

OPT = ["-O1", "-O2"]
DBG = ["-g0", "-g3"]
ARCH = [["-mips2"], ["-mips3", "-32"]]  # -O0/-O3/-g2/-mips1 were never seen in this ROM
EXTRA = [[], ["-trapuv"]]
BASE = match.DEFAULT_FLAGS[3:]  # -G 0 -non_shared -Xcpluscomm -w -I...


def score(cfile, fn, flags, want, size):
    try:
        got, masks = match.compiled(cfile, fn, flags, size)
    except Exception:
        return None
    if len(got) > len(want) and not any(got[len(want):]):
        got = got[:len(want)]
    if len(got) != len(want):
        return 1000 + abs(len(got) - len(want))
    a, b = match.mask(want, masks), match.mask(got, masks)
    return sum(x != y for x, y in zip(a, b))


def main():
    seg = sys.argv[1]
    limit = int(sys.argv[2]) if len(sys.argv) > 2 else 10**9
    skip = set((match.ROOT / "config" / f"{seg}.asm_only.txt").read_text().split())
    rank = match.ROOT / "build" / f"rank_{seg}.txt"
    order = [l.split()[0] for l in rank.read_text().splitlines()] if rank.exists() else []
    files = {p.stem: p for p in (match.ROOT / "src" / seg / "wip").glob("func_*.c") if p.stem not in skip}
    todo = [n for n in order if n in files][:limit]
    log = match.ROOT / "build" / f"flag_sweep_{seg}.txt"
    done = {l.split()[0] for l in log.read_text().splitlines()} if log.exists() else set()
    for fn in [n for n in todo if n not in done]:
        src = files[fn]
        want, _ = match.original(seg, fn)
        text = src.read_text()
        body = text.split("\n", 1)[1] if text.startswith("// FLAGS") else text
        cur = match.file_flags(src)
        best = (score(src, fn, cur, want, len(want)), " ".join(cur[:3]))
        tmp = match.ROOT / "src" / seg / "wip" / f"{fn}.sweep.c"
        for o, g, a, x in itertools.product(OPT, DBG, ARCH, EXTRA):
            fl = [o, g, *a, *x]
            tmp.write_text("// FLAGS: " + " ".join(fl) + "\n" + body)
            s = score(tmp, fn, fl + BASE, want, len(want))
            if s is not None and (best[0] is None or s < best[0]):
                best = (s, " ".join(fl))
            if s == 0:
                break
        tmp.unlink(missing_ok=True)
        if best[0] == 0:
            dst = match.ROOT / "src" / seg / f"{fn}.c"
            dst.write_text("// FLAGS: " + best[1] + "\n" + body)
            src.unlink()
            status = "MATCHED"
        else:
            status = "no match"
        with log.open("a") as f:
            f.write(f"{fn} {status} best={best[0]} flags={best[1]}\n")


if __name__ == "__main__":
    main()
