#!/usr/bin/env python3
"""Move functions of the `unknown` folder into the module that alone calls them. Run in WSL. usage: layout_callers.py <seg>
Evidence: every `jal` to the function comes from functions of one single module (repeated until nothing changes).
Edits config/<seg>.layout.txt; run tools/srcsort.py afterwards to move the files."""
import re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
seg = sys.argv[1]
table = ROOT / "config" / f"{seg}.layout.txt"
folder = dict(l.split() for l in table.read_text().splitlines())
callers, cur = {}, None
for l in (ROOT / "asm" / seg / "text.s").read_text().splitlines():
    m = re.match(r"glabel (func_[0-9A-F]{8})$", l)
    if m:
        cur = m.group(1)
    m = re.search(r"\bjal\s+(func_[0-9A-F]{8})", l)
    if m and cur and m.group(1) != cur:
        callers.setdefault(m.group(1), set()).add(cur)
moved = 0
while True:
    step = 0
    for fn in [f for f, d in folder.items() if d == "unknown"]:
        mods = {folder[c] for c in callers.get(fn, ()) if c in folder}
        if len(mods) == 1 and "unknown" not in mods:
            folder[fn] = mods.pop()
            step += 1
    moved += step
    if not step:
        break
table.write_text("".join(f"{f} {d}\n" for f, d in folder.items()))
print(f"{seg}: {moved} functions moved out of unknown, {sum(d == 'unknown' for d in folder.values())} left")
