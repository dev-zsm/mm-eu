#!/usr/bin/env python3
"""Inventory of the overlays: files of the ROM file table that end with a relocation header. Run in WSL (after tools/extract.py).
usage: overlays.py            writes config/overlays.txt:  <file index> <vrom start> <text> <data> <rodata> <bss> <relocs>  (hex sizes)
An overlay file is  text | data | rodata | header(text, data, rodata, bss, reloc count) | relocations | footer(offset of the header
from the end of the file).  A file is only listed when every size is consistent with the file size, so a false positive is unlikely."""
import re, struct
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def header(data: bytes):
    if len(data) < 32 or len(data) % 16:
        return None
    foot = struct.unpack(">I", data[-4:])[0]
    if foot < 24 or foot > len(data) or foot % 4:
        return None
    start = len(data) - foot
    text, dat, ro, bss, n = struct.unpack_from(">5I", data, start)
    if n > 0x4000 or text % 4 or dat % 4 or ro % 4 or text == 0 or text > start or text + dat + ro > start:
        return None
    if 20 + n * 4 + 4 > foot:  # the relocations and the footer must fit after the header
        return None
    return text, dat, ro, bss, n


def main():
    rows = []
    for f in sorted((ROOT / "extracted").glob("*.bin")):
        m = re.fullmatch(r"(\d{4})_([0-9A-F]{8})\.bin", f.name)
        h = m and header(f.read_bytes())
        if h:
            rows.append((int(m.group(1)), int(m.group(2), 16), *h))
    out = "".join(f"{i:04d} {v:08X} {t:X} {d:X} {r:X} {b:X} {n}\n" for i, v, t, d, r, b, n in rows)
    (ROOT / "config" / "overlays.txt").write_text(out)
    print(f"{len(rows)} overlays, {sum(r[2] for r in rows):#x} bytes of code in total -> config/overlays.txt")


if __name__ == "__main__":
    main()
