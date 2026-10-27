#!/usr/bin/env python3
"""Rank the unmatched functions of a segment by how close they are. Run in WSL. usage: rank_wip.py <seg>
Writes build/rank_<seg>.txt: `<fn> <size> <status>` sorted, closest first (status = N/M instr differ, or SIZE a vs b)."""
import re, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import match

seg = sys.argv[1]
asm_file = match.ROOT / "config" / f"{seg}.asm_only.txt"
skip = set(asm_file.read_text().split()) if asm_file.exists() else set()
rows = []
for f in sorted((match.ROOT / "src" / seg / "wip").glob("func_*.c")):
    n = f.stem
    if n in skip:
        continue
    try:
        want, _ = match.original(seg, n)
        got, masks = match.compiled(f, n, match.file_flags(f), len(want))
        if len(got) > len(want) and not any(got[len(want):]):
            got = got[:len(want)]
        if len(got) != len(want):
            rows.append((abs(len(got) - len(want)) / len(want) + 1, n, len(want), f"SIZE rom {len(want):#x} ours {len(got):#x}"))
        else:
            a, b = match.mask(want, masks), match.mask(got, masks)
            bad = sum(x != y for x, y in zip(a, b))
            rows.append((bad / len(a), n, len(want), f"{bad}/{len(a)} instr differ"))
    except Exception as e:
        rows.append((9, n, 0, f"does not compile ({type(e).__name__})"))
rows.sort()
(match.ROOT / "build" / f"rank_{seg}.txt").write_text("".join(f"{n} {s:#x} {st}\n" for _, n, s, st in rows))
print(len(rows), "ranked;", sum(1 for r in rows if "instr differ" in r[3]), "same size,", sum(1 for r in rows if r[3].startswith("SIZE")), "size differs")
