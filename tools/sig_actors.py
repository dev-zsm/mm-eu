#!/usr/bin/env python3
"""Signatures of the actor handlers of the overlays, from the relocation table of the ROM. Run in WSL (after tools/overlays.py and
tools/overlay_split.py).  usage: sig_actors.py      writes config/overlays.signatures.txt (input of tools/retype.py)
An actor overlay starts its .data with a profile whose words at 0x10, 0x14, 0x18 and 0x1C are function pointers (init, destroy, update,
draw): each is a relocation of type R_MIPS_32 in the data section. The overlay is linked at its own address, so the offset of a
function is found by choosing the load address for which every handler pointer is the start of a function of the disassembly and the
most `jal` targets of the overlay land on function starts. An overlay whose load address is not unique is skipped.
Every listed function takes (Actor *thisx, PlayState *play)."""
import re, struct
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SLOTS = ((0x10, "init"), (0x14, "destroy"), (0x18, "update"), (0x1C, "draw"))
R_MIPS_32, R_MIPS_26 = 2, 4


def analyse(idx: str, f: Path):
    """({function: slot}, minimum instance size) of one overlay, or (None, reason)."""
    b = f.read_bytes()
    hdr = len(b) - struct.unpack(">I", b[-4:])[0]
    text, data, ro, bss, n = struct.unpack_from(">5I", b, hdr)
    rel = [(x >> 30, (x >> 24) & 0x3F, x & 0xFFFFFF) for x in struct.unpack_from(f">{n}I", b, hdr + 20)]
    in_data = {off: t for s, t, off in rel if s == 2}
    slots = [(name, struct.unpack_from(">I", b, text + off)[0]) for off, name in SLOTS if in_data.get(off) == R_MIPS_32]
    if [s for s, _ in slots[:3]] != ["init", "destroy", "update"]:
        return None, "no actor profile"
    size = struct.unpack_from(">I", b, text + 0x0C)[0]
    if not 0x144 <= size <= 0x4000:
        return None, f"instance size {size:#x}"
    asm = (ROOT / "asm" / "overlays" / idx / "text.s").read_text()
    starts = {int(m, 16) - 0x80000000 for m in re.findall(r"^glabel func_(8[0-9A-F]{7})$", asm, re.M)}
    jals = [((struct.unpack_from(">I", b, off)[0] & 0x3FFFFFF) << 2) | 0x80000000 for s, t, off in rel if s == 1 and t == R_MIPS_26]
    best = {}
    for s in starts:
        base = slots[0][1] - s
        if all(p - base in starts for _, p in slots):
            best[base] = sum(t - base in starts for t in jals)
    if not best:
        return None, "no load address fits"
    top = max(best.values())
    bases = [k for k, v in best.items() if v == top]
    if len(bases) != 1:
        return None, "load address not unique"
    return {f"func_{0x80000000 + p - bases[0]:08X}": name for name, p in slots}, size


def main():
    rows, skipped, sizes = [], {}, []
    for line in (ROOT / "config" / "overlays.txt").read_text().splitlines():
        idx = line.split()[0]
        f = next((ROOT / "extracted").glob(f"{idx}_*.bin"))
        found, info = analyse(idx, f)
        if found is None:
            skipped[info.split()[0] + " " + info.split()[1]] = skipped.get(info.split()[0] + " " + info.split()[1], 0) + 1
            continue
        sizes.append(info)
        for fn, slot in found.items():
            rows.append(f"ovl{idx} {fn} actor.h void {fn}(Actor *thisx, PlayState *play)   # {slot} slot of the actor profile (relocations of the data section)\n")
    (ROOT / "config" / "overlays.signatures.txt").write_text("".join(rows))
    print(f"{len(rows)} handlers in {len(sizes)} actor overlays (smallest instance size {min(sizes):#x}); skipped {skipped}")


if __name__ == "__main__":
    main()
