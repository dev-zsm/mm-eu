#!/usr/bin/env python3
"""Put back together the functions splat cut in pieces. IDO places the case bodies of a `switch` after the first `jr $ra`; when every
body returns, splat ends the function there and prints each body as a function of its own (see docs/TOOLS.md, hardjt.fragments).
`config/<seg>/merge.txt` lists, one per line, `head fragment fragment ...`: this script edits asm/<seg>/text.s so that the fragments
become `alabel`s inside the head (one `nonmatching`, one `endlabel`, the size of the head is the sum). Idempotent; run it after `splat`
(make split does).   usage: merge_frags.py [seg ...]   (default: boot code)"""
import re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def merge(seg: str) -> int:
    cfg = ROOT / "config" / seg / "merge.txt"
    asm = ROOT / "asm" / seg / "text.s"
    if not cfg.exists() or not asm.exists():
        return 0
    text, done = asm.read_text(), 0
    for line in cfg.read_text().splitlines():
        line = line.split("#")[0].split()
        if len(line) < 2:
            continue
        head, frags = line[0], line[1:]
        m = re.search(rf"^nonmatching {head}, (0x[0-9A-Fa-f]+)$", text, re.M)
        if not m:
            continue
        size, last = int(m.group(1), 16), head
        for f in frags:
            r = re.compile(rf"^endlabel {last}\n\nnonmatching {f}, (0x[0-9A-Fa-f]+)\n\nglabel {f}\n", re.M)
            m2 = r.search(text)
            if not m2:
                break
            size += int(m2.group(1), 16)
            text = text[:m2.start()] + f"alabel {f}\n" + text[m2.end():]
            last = f
            done += 1
        if last != head:
            text = text.replace(f"endlabel {last}\n", f"endlabel {head}\n", 1)
            text = re.sub(rf"^nonmatching {head}, 0x[0-9A-Fa-f]+$", f"nonmatching {head}, 0x{size:X}", text, count=1, flags=re.M)
    if done:
        asm.write_text(text)
    return done


if __name__ == "__main__":
    for s in sys.argv[1:] or ["boot", "code"]:
        n = merge(s)
        if n:
            print(f"{s}: {n} fragments merged")
