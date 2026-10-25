#!/usr/bin/env python3
"""Move to src/<seg>/wip/ every C function whose bytes in the rebuilt segment differ from the ROM.
Run in WSL.  usage: quarantine.py <boot|code>
Rebuilds the segment with tools/build_seg.py, compares each src/<seg>/func_*.c with the ROM bytes of its function
and moves the files that differ. Their callers and the rest of the segment fall back to the original assembly, so one
pass is enough. Use it after a batch of unchecked work (stopped agents, hand edits); `make check` stays the judge."""
import re, shutil, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import match  # noqa: E402


def main():
    seg = sys.argv[1]
    orig = {"boot": "build/boot.bin", "code": "extracted/0049_00C8A000.bin"}[seg]
    subprocess.run([sys.executable, str(ROOT / "tools/build_seg.py"), seg, str(ROOT / orig)], capture_output=True, text=True)
    built = (ROOT / "build" / seg / f"{seg}.fn.bin").read_bytes()
    rom, base = match._rom(seg), match.SEG[seg][1]
    sizes = match._sizes(seg)
    wip = ROOT / "src" / seg / "wip"
    wip.mkdir(exist_ok=True)
    moved = []
    for f in sorted((ROOT / "src" / seg).glob("func_*.c")):
        name = f.stem
        if name not in sizes:
            continue
        off = int(name.rsplit("_", 1)[1], 16) - base
        # the segment file starts at the first function: `built` and `rom` share the same origin
        if built[off:off + sizes[name]] != rom[off:off + sizes[name]]:
            shutil.move(str(f), str(wip / f.name))
            moved.append(name)
    print(f"{seg}: {len(moved)} C functions moved to wip" + (": " + " ".join(moved) if moved else ""))


if __name__ == "__main__":
    main()
