#!/usr/bin/env python3
"""Check that a C function compiles (IDO 7.1) to exactly the bytes in the ROM.
Run inside WSL.  usage: match.py <boot|code> <function> <file.c>
Relocated fields (jal targets, %hi/%lo, gp-relative) are masked on both sides, since the
original bytes are already linked and the .o is not."""
import functools, re, struct, subprocess, sys, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import names as _names  # noqa: E402
import objcache  # noqa: E402

NAMES = {**_names.load("boot"), **_names.load("code")}
import os  # noqa: E402
CC = objcache._compiler("71")  # MM_CC, else ~/ido71/cc (native disk, ~4x faster than /mnt/c), else tools/vendor
class _Segments(dict):
    """boot and code, plus any overlay as `ovlNNNN` (file index NNNN): its file in extracted/, linked at address 0 and read at 0x80000000."""
    def __missing__(self, seg):
        if re.fullmatch(r"ovl\d{4}", seg):
            return next((ROOT / "extracted").glob(f"{seg[3:]}_*.bin")), 0x80000000
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


def compiled(cfile: Path, name: str, flags: list[str], want_len: int = 0):
    name = NAMES.get(name, name)  # the C file defines the real name; files and the ROM table use the splat name
    obj = objcache.compile_obj(cfile, flags)  # cached by content: an unchanged file is not compiled again
    with tempfile.TemporaryDirectory() as d:
        syms = run("mips-linux-gnu-nm", str(obj))
        start = int(re.search(rf"^([0-9a-f]+) T {name}$", syms, re.M).group(1), 16)
        sec = run("mips-linux-gnu-objdump", "-h", str(obj))
        tsize = int(re.search(r"\.text\s+([0-9a-f]+)", sec).group(1), 16)
        subprocess.run(["mips-linux-gnu-objcopy", "-O", "binary", "--only-section=.text", str(obj), d + "/t.bin"], check=True)
        blob = (Path(d) / "t.bin").read_bytes()
        # function ends at the next text symbol (or end of section)
        later = sorted(int(m.group(1), 16) for m in re.finditer(r"^([0-9a-f]+) [Tt] ", syms, re.M) if int(m.group(1), 16) > start)
        end = later[0] if later else tsize
        if want_len and want_len > end - start:  # the ROM 'function' may hold several tiny ones (splat split)
            end = min(tsize, start + want_len)
            if any(blob[end:tsize]):  # the file holds more code than the ROM function: report it as a size difference
                end = tsize
        masks = {}
        for m in re.finditer(r"^([0-9a-f]{8})\s+[0-9a-f]+\s+(R_MIPS_\w+)", run("mips-linux-gnu-readelf", "-r", str(obj)), re.M):
            off = int(m.group(1), 16)
            if start <= off < end and m.group(2) in MASKS:
                masks[off - start] = MASKS[m.group(2)]
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
