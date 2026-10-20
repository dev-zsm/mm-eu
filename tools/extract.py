#!/usr/bin/env python3
"""Extract every file from the dmadata table of the MM PAL Rev 1 ROM into extracted/."""
import hashlib, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ROM = ROOT / "baserom" / "The Legend of Zelda Majora's Mask (Europe).z64"
OUT = ROOT / "extracted"
SHA1 = "bb4e4757d10727c7584c59c1f2e5f44196e9c293"
DMADATA = 0x1A8D0


def yaz0(src: bytes) -> bytes:
    assert src[:4] == b"Yaz0", "not Yaz0"
    size = struct.unpack(">I", src[4:8])[0]
    dst = bytearray()
    s = 16
    while len(dst) < size:
        code = src[s]; s += 1
        for bit in range(8):
            if len(dst) >= size:
                break
            if code & (0x80 >> bit):
                dst.append(src[s]); s += 1
            else:
                b1, b2 = src[s], src[s + 1]; s += 2
                back = ((b1 & 0xF) << 8 | b2) + 1
                n = b1 >> 4
                if n == 0:
                    n = src[s] + 0x12; s += 1
                else:
                    n += 2
                for _ in range(n):  # byte-by-byte: copies may overlap
                    dst.append(dst[-back])
    return bytes(dst)


def main():
    rom = ROM.read_bytes()
    if hashlib.sha1(rom).hexdigest() != SHA1:
        sys.exit("ROM SHA-1 mismatch: expected MM PAL Rev 1")
    assert yaz0(b"Yaz0" + struct.pack(">I", 3) + bytes(8) + b"\xE0abc") == b"abc"  # self-check

    OUT.mkdir(exist_ok=True)
    rows = []
    for i in range(0x10000):
        vs, ve, ps, pe = struct.unpack_from(">4I", rom, DMADATA + i * 16)
        if i and vs == 0 and ve == 0:
            break
        if ps == 0xFFFFFFFF:  # file absent from ROM
            rows.append(f"{i:04d} {vs:08X} {ve:08X} absent")
            continue
        data = yaz0(rom[ps:pe]) if pe else rom[ps:ps + ve - vs]
        assert len(data) == ve - vs, f"file {i}: size {len(data):X} != {ve - vs:X}"
        (OUT / f"{i:04d}_{vs:08X}.bin").write_bytes(data)
        rows.append(f"{i:04d} {vs:08X} {ve:08X} {'yaz0' if pe else 'raw'}")
    (OUT / "filetable.txt").write_text("\n".join(rows) + "\n")
    print(f"{len(rows)} entries extracted to {OUT}")


if __name__ == "__main__":
    main()
