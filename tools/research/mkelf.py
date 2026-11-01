#!/usr/bin/env python3
"""Wrap a raw N64 code blob in a minimal MIPS big-endian ELF so Ghidra auto-detects it.
usage: mkelf.py <in.bin> <vaddr hex> <out.elf> [entry hex]"""
import struct, sys


def mkelf(code: bytes, vaddr: int, entry: int) -> bytes:
    ehsize, phsize, off = 52, 32, 0x1000
    ident = b"\x7fELF" + bytes([1, 2, 1]) + bytes(9)  # 32-bit, big-endian, v1
    # e_flags 0x20000000 = EF_MIPS_ARCH_3 (VR4300 is MIPS III)
    eh = ident + struct.pack(">HHIIIIIHHHHHH", 2, 8, 1, entry, ehsize, 0, 0x20000000,
                             ehsize, phsize, 1, 0, 0, 0)
    ph = struct.pack(">8I", 1, off, vaddr, vaddr, len(code), len(code), 7, 0x10)  # PT_LOAD RWX
    return (eh + ph).ljust(off, b"\0") + code


if __name__ == "__main__":
    src, vaddr, dst = sys.argv[1], int(sys.argv[2], 16), sys.argv[3]
    entry = int(sys.argv[4], 16) if len(sys.argv) > 4 else vaddr
    elf = mkelf(open(src, "rb").read(), vaddr, entry)
    assert elf[:4] == b"\x7fELF" and struct.unpack_from(">H", elf, 18)[0] == 8  # EM_MIPS
    open(dst, "wb").write(elf)
    print(f"{dst}: {len(elf) - 0x1000:#x} bytes @ {vaddr:#010x}")
