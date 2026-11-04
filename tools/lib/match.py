#!/usr/bin/env python3
"""Check that a C function compiles (IDO 7.1) to exactly the bytes in the ROM.
Run inside WSL.  usage: match.py <boot|code> <function> <file.c>
Relocated fields (jal targets, %hi/%lo, gp-relative) are masked on both sides, since the
original bytes are already linked and the .o is not."""
import collections, functools, re, struct, subprocess, sys, tempfile, threading
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import names as _names  # noqa: E402
import objcache  # noqa: E402

NAMES = {**_names.load("boot"), **_names.load("code")}
CC = objcache._compiler("71")  # MM_CC, else ~/ido71/cc (native disk, ~4x faster than /mnt/c), else tools/vendor
class _Segments(dict):
    """boot and code, plus any overlay as `ovlNNNN` (file index NNNN): its file in extracted/, linked at address 0 and read at 0x80000000."""
    def __missing__(self, seg):
        if re.fullmatch(r"ovl\d{4}", seg):
            self[seg] = next((ROOT / "extracted").glob(f"{seg[3:]}_*.bin")), 0x80000000  # remembered: the folder has 1,500 files
            return self[seg]
        raise KeyError(seg)


SEG = _Segments({"boot": (ROOT / "build/boot.bin", 0x80080000), "code": (ROOT / "extracted/0049_00C8A000.bin", 0x800A5FE0)})


def asm_file(seg: str) -> Path:
    return ROOT / (f"asm/overlays/{seg[3:]}/text.s" if seg.startswith("ovl") else f"asm/{seg}/text.s")
CC53 = objcache._compiler("53")  # libultra/libc files built with the older IDO 5.3: `// COMPILER: ido53` in their first lines
DEFAULT_FLAGS = ["-O2", "-g3", "-mips2", "-G", "0", "-non_shared", "-Xcpluscomm", "-w", "-I" + str(ROOT / "include")]
# relocation type -> mask of bits that the linker rewrites
MASKS = {"R_MIPS_26": 0x03FFFFFF, "R_MIPS_HI16": 0xFFFF, "R_MIPS_LO16": 0xFFFF,
         "R_MIPS_GPREL16": 0xFFFF, "R_MIPS_GOT16": 0xFFFF, "R_MIPS_CALL16": 0xFFFF, "R_MIPS_32": 0xFFFFFFFF}


def run(*a):
    return subprocess.run(a, check=True, capture_output=True, text=True).stdout


@functools.lru_cache(maxsize=None)
def _sizes(seg: str) -> dict:
    """{function: size} from the splat asm (`nonmatching name, size`), read once."""
    text = asm_file(seg).read_text()
    return {m.group(1): int(m.group(2), 16) for m in re.finditer(r"^nonmatching (\w+), (0x[0-9A-Fa-f]+)", text, re.M)}


@functools.lru_cache(maxsize=None)
def _rom(seg: str) -> bytes:
    return SEG[seg][0].read_bytes()


def original(seg: str, name: str):
    """(bytes, offset) of `name` from the splat asm: `nonmatching name, size`."""
    size = _sizes(seg)[name]
    off = int(name.rsplit("_", 1)[1], 16) - SEG[seg][1]
    return _rom(seg)[off:off + size], off


def compiler_for(cfile: Path) -> Path:
    """IDO 5.3 when one of the first lines of the file says `// COMPILER: ido53`, else IDO 7.1."""
    head = cfile.read_text().splitlines()[:3]
    return CC53 if any(re.match(r"// COMPILER: ido53\s*$", l) for l in head) else CC


TARGET_STATS = collections.Counter()   # relocations whose target was compared with the ROM / was of unknown address
RELOCS = {}   # thread -> [(offset in the function, relocation type, symbol)] of the last compiled() call of that thread


def last_relocs():
    return RELOCS.get(threading.get_ident(), [])


def _address(sym: str):
    """The address a symbol stands for: its splat name, or the splat name a registered name replaces. None if unknown."""
    m = re.fullmatch(r"(?:func|D)_([0-9A-F]{8})", sym)
    if m:
        return int(m.group(1), 16)
    m = _REVERSE().get(sym)
    return int(m[-8:], 16) if m else None


@functools.lru_cache(maxsize=None)
def _REVERSE():
    return {v: k for k, v in NAMES.items()}


def check_targets(rom: bytes, got: bytes, relocs) -> list:
    """The symbols whose address, once linked, would not be the one the ROM has: [(offset, symbol)]. `rom` and `got` are the code of
    the function in the ROM and in our object (whose immediate fields hold the addends); a symbol of unknown address is not checked."""
    word = lambda b, o: struct.unpack(">I", b[o:o + 4])[0]
    s16 = lambda v: v - 0x10000 if v & 0x8000 else v
    bad = []
    for i, (off, typ, sym) in enumerate(relocs):
        a = _address(sym)
        if a is None or off + 4 > len(rom) or off + 4 > len(got):
            TARGET_STATS["unknown address"] += 1
            continue
        TARGET_STATS["compared"] += 1
        if typ == "R_MIPS_26":
            want = ((a + (word(got, off) & 0x3FFFFFF) * 4) >> 2) & 0x3FFFFFF
            ok = word(rom, off) & 0x3FFFFFF == want
        elif typ == "R_MIPS_LO16":
            ok = word(rom, off) & 0xFFFF == (a + s16(word(got, off) & 0xFFFF)) & 0xFFFF
        elif typ == "R_MIPS_HI16":
            lo = next((o for o, t, s2 in relocs[i + 1:] if t == "R_MIPS_LO16" and s2 == sym), None)
            if lo is None or lo + 4 > len(got):
                continue
            addend = ((word(got, off) & 0xFFFF) << 16) + s16(word(got, lo) & 0xFFFF)
            ok = word(rom, off) & 0xFFFF == ((a + addend + 0x8000) >> 16) & 0xFFFF
        else:
            continue
        if not ok:
            bad.append((off, sym))
    return bad


R_NAMES = {2: "R_MIPS_32", 4: "R_MIPS_26", 5: "R_MIPS_HI16", 6: "R_MIPS_LO16", 7: "R_MIPS_GPREL16", 9: "R_MIPS_GOT16", 11: "R_MIPS_CALL16"}


@functools.lru_cache(maxsize=8192)
def elf_text(path: str):
    """(code of .text, its size, {symbol: (offset, size)} of the symbols in .text, [(offset, relocation type, symbol)] of .rel.text)
    of an ELF32 big-endian object, read directly: this used to be four calls to the binutils per function, the bulk of every check."""
    d = Path(path).read_bytes()
    shoff, = struct.unpack_from(">I", d, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from(">HHH", d, 0x2E)
    secs = [struct.unpack_from(">10I", d, shoff + i * shentsize) for i in range(shnum)]   # name type flags addr offset size link info align entsize

    def cstr(base, o):
        return d[base + o:d.index(b"\0", base + o)].decode()

    shstr = secs[shstrndx][4]
    names = [cstr(shstr, s[0]) for s in secs]
    ti = names.index(".text")
    symtab = next(i for i, s in enumerate(secs) if s[1] == 2)
    strtab = secs[secs[symtab][6]][4]
    syms = []
    for k in range(secs[symtab][5] // 16):
        st_name, st_value, st_size, st_info, _, st_shndx = struct.unpack_from(">IIIBBH", d, secs[symtab][4] + 16 * k)
        # a relocation against a section is named after the section, as readelf prints it
        syms.append((names[st_shndx] if st_info & 15 == 3 and st_shndx < len(names) else cstr(strtab, st_name), st_value, st_size, st_shndx, st_info & 15))
    text = d[secs[ti][4]:secs[ti][4] + secs[ti][5]]
    inside = {n: (v, z) for n, v, z, sh, t in syms if sh == ti and n and t != 3}   # not the symbol of the section itself
    relocs = []
    for s in secs:
        if s[1] == 9 and s[7] == ti:   # SHT_REL of .text
            for k in range(s[5] // 8):
                off, info = struct.unpack_from(">II", d, s[4] + 8 * k)
                relocs.append((off, R_NAMES.get(info & 255, f"R_MIPS_{info & 255}"), syms[info >> 8][0]))
    return text, secs[ti][5], inside, relocs


def compiled(cfile: Path, name: str, flags: list[str], want_len: int = 0):
    name = NAMES.get(name, name)  # the C file defines the real name; files and the ROM table use the splat name
    RELOCS[threading.get_ident()] = []
    obj = objcache.compile_obj(cfile, flags)  # cached by content: an unchanged file is not compiled again
    blob, tsize, inside, relocs = elf_text(str(obj))
    if name not in inside:   # a static function nobody calls is not emitted at all
        raise KeyError(f"{name} is not defined in the object")
    start = inside[name][0]
    # function ends at the next text symbol (or end of section)
    later = sorted(v for v, _ in inside.values() if v > start)
    end = later[0] if later else tsize
    if want_len and want_len > end - start:  # the ROM 'function' may hold several tiny ones (splat split)
        end = min(tsize, start + want_len)
        if any(blob[end:tsize]):  # the file holds more code than the ROM function: report it as a size difference
            end = tsize
    masks = {}
    for off, typ, sym in relocs:
        if start <= off < end and typ in MASKS:
            masks[off - start] = MASKS[typ]
            RELOCS.setdefault(threading.get_ident(), []).append((off - start, typ, sym))
    return blob[start:end], masks


def mask(code: bytes, masks: dict) -> list[int]:
    words = list(struct.unpack(f">{len(code) // 4}I", code))
    for off, m in masks.items():
        if off // 4 < len(words):
            words[off // 4] &= ~m
    return words


def file_flags(cfile: Path) -> list[str]:
    """Optimisation flags from a first-line `// FLAGS: -O1 -g0` comment, else the default."""
    m = re.match(r"// FLAGS: (.*)", cfile.read_text().splitlines()[0])
    return (m.group(1).split() + DEFAULT_FLAGS[3:]) if m else DEFAULT_FLAGS


def main():
    seg, name, cfile = sys.argv[1], sys.argv[2], Path(sys.argv[3])
    flags = file_flags(cfile)
    want, _ = original(seg, name)
    got, masks = compiled(cfile, name, flags, len(want))
    if len(got) > len(want) and not any(got[len(want):]):  # IDO pads .text to 16 bytes
        got = got[:len(want)]
    a, b = mask(want, masks), mask(got, masks)
    if len(want) != len(got):
        print(f"{name}: SIZE DIFFERS (rom {len(want):#x}, ours {len(got):#x})"); sys.exit(1)
    bad = [i * 4 for i, (x, y) in enumerate(zip(a, b)) if x != y]
    if bad:
        print(f"{name}: {len(bad)}/{len(a)} instructions differ, first at +{bad[0]:#x}"); sys.exit(1)
    print(f"{name}: MATCH ({len(want):#x} bytes)")


if __name__ == "__main__":
    main()
