#!/usr/bin/env python3
"""Run decomp-permuter over every unmatched function of a segment, smallest first, and keep what matches.
Run in WSL.  usage: permute_all.py <seg> [seconds_per_function=120] [first_n]
A function is only promoted to src/<seg>/ if tools/match.py says MATCH. Log: build/perm/log_<seg>.txt"""
import re, subprocess, sys, time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PERMUTER = ROOT / "tools/vendor/decomp-permuter/permuter.py"
sys.path.insert(0, str(ROOT / "tools"))
import match  # noqa: E402


def sizes(seg):
    t = (ROOT / "asm" / seg / "text.s").read_text()
    return {m.group(1): int(m.group(2), 16) for m in re.finditer(r"^nonmatching (\w+), (0x[0-9A-Fa-f]+)", t, re.M)}


def main():
    seg = sys.argv[1]
    budget_default = int(sys.argv[2]) if len(sys.argv) > 2 else 120
    limit = int(sys.argv[3]) if len(sys.argv) > 3 else 10**9
    skip = set((ROOT / "config" / f"{seg}.asm_only.txt").read_text().split()) \
        if (ROOT / "config" / f"{seg}.asm_only.txt").exists() else set()
    sz = sizes(seg)
    todo = sorted((p.stem for p in (ROOT / "src" / seg / "wip").glob("func_*.c") if p.stem not in skip),
                  key=lambda n: sz.get(n, 0))[:limit]
    rank = ROOT / "build" / f"rank_{seg}.txt"  # from tools/rank_wip.py: closest to a match first
    status = {}
    if rank.exists():
        order = []
        for l in rank.read_text().splitlines():
            n, _, st = l.split(" ", 2)
            order.append(n); status[n] = st
        todo = sorted(todo, key=lambda n: order.index(n) if n in order else len(order))
    log = (ROOT / "build/perm" / f"log_{seg}.txt")
    log.parent.mkdir(parents=True, exist_ok=True)
    done = {l.split()[1] for l in log.read_text().splitlines() if l[:1].isdigit()} if log.exists() else set()
    todo = [f for f in todo if f not in done]  # resume: skip functions already tried
    won = 0
    for n, fn in enumerate(todo, 1):
        subprocess.run([sys.executable, str(ROOT / "tools/permute_setup.py"), seg, fn], check=True, capture_output=True)
        d = ROOT / "build/perm" / fn
        t0 = time.time()
        budget = 300 if "instr differ" in status.get(fn, "") else budget_default  # near misses get more time
        try:
            subprocess.run([sys.executable, str(PERMUTER), str(d), "-j", "6", "--stop-on-zero"],
                           capture_output=True, timeout=budget)
        except subprocess.TimeoutExpired:
            pass
        best = sorted(d.glob("output-0-*/source.c"))
        status = "no match"
        if best:
            wip = ROOT / "src" / seg / "wip" / f"{fn}.c"
            flags = wip.read_text().splitlines()[0]
            dst = ROOT / "src" / seg / f"{fn}.c"
            body = best[0].read_text()
            dst.write_text((flags + "\n" if flags.startswith("// FLAGS") else "") + body)
            r = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), seg, fn, str(dst)], capture_output=True, text=True)
            if "MATCH" in r.stdout and "differ" not in r.stdout:
                wip.unlink()
                won += 1
                status = "MATCHED (promoted to src/)"
            else:
                dst.unlink()
                status = "permuter claimed 0 but matcher disagrees"
        with log.open("a") as f:
            f.write(f"{n}/{len(todo)} {fn} {sz.get(fn, 0):#x} {time.time() - t0:.0f}s {status}\n")
    with log.open("a") as f:
        f.write(f"DONE: {won} matched out of {len(todo)}\n")


if __name__ == "__main__":
    main()
