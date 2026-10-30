#!/usr/bin/env python3
"""Ghidra pseudo-C for one code segment: 32-bit pass (clean constants), 64-bit pass for
functions using 64-bit instructions the 32-bit language can't decode.
usage: decomp.py <name> <code.bin> <vram hex>  ->  decomp/<name>.c"""
import os, re, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
GHIDRA = os.environ.get("GHIDRA_HEADLESS", "analyzeHeadless")  # the support/analyzeHeadless script of your Ghidra install
LANGS = {"32": ("MIPS:BE:32:default", "default"), "64": ("MIPS:BE:64:64-32addr", "o32")}
BROKEN = "halt_baddata"


def ghidra(elf: Path, lang: str, outdir: Path) -> Path:
    proc, cspec = LANGS[lang]
    outdir.mkdir(parents=True, exist_ok=True)
    subprocess.run([GHIDRA, str(ROOT / "build" / "ghidra"), "mm-eu", "-import", str(elf), "-overwrite",
                    "-processor", proc, "-cspec", cspec, "-scriptPath", str(ROOT / "tools" / "ghidra"),
                    "-postScript", "ExportDecomp.java", str(outdir)],
                   check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    return outdir / (elf.stem + ".c")


def blocks(text: str) -> dict:
    parts = re.split(r"^(?=// [0-9a-f]{8} size )", text, flags=re.M)
    return {p[3:11]: p for p in parts if p.startswith("// ")}


def merge(c32: str, c64: str) -> tuple[str, int]:
    b64, fixed, out = blocks(c64), 0, []
    for addr, body in blocks(c32).items():
        if BROKEN in body and addr in b64:
            body, fixed = b64[addr], fixed + 1
        out.append(body)
    return "".join(out), fixed


def main():
    name, binfile, vram = sys.argv[1], Path(sys.argv[2]), int(sys.argv[3], 16)
    sys.path.insert(0, str(ROOT / "tools"))
    from mkelf import mkelf
    elf = ROOT / "build" / f"{name}.elf"
    elf.write_bytes(mkelf(binfile.read_bytes(), vram, vram))
    c32 = ghidra(elf, "32", ROOT / "build" / "d32").read_text()
    c64 = ghidra(elf, "64", ROOT / "build" / "d64").read_text()
    text, fixed = merge(c32, c64)
    (ROOT / "decomp" / f"{name}.c").write_text(text)
    print(f"{name}: {len(blocks(text))} functions, {fixed} from 64-bit pass, "
          f"{text.count(BROKEN)} still broken")


if __name__ == "__main__":
    if sys.argv[1:] == ["--test"]:
        a = "// 80000000 size 4\nok\n// 80000004 size 4\nhalt_baddata\n"
        b = "// 80000000 size 4\nx\n// 80000004 size 4\nfixed\n"
        assert merge(a, b) == ("// 80000000 size 4\nok\n// 80000004 size 4\nfixed\n", 1)
        print("ok")
    else:
        main()
