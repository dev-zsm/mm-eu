#!/usr/bin/env python3
"""Disassemble overlays with splat and check that the assembly rebuilds the extracted file byte for byte. Run in WSL.
usage: overlay_split.py [--smallest N] [<file index> ...]      (default: every overlay of config/overlays.txt)
Per overlay <idx>: config in build/overlays/<idx>.yaml (generated), assembly in asm/overlays/<idx>/, result IDENTICAL or DIFFERENT.
An overlay is linked at address 0 and relocated at load time, so the code is disassembled at 0x80000000, which keeps the
`jal` targets of the file readable; the header, relocations and footer after the sections are not disassembled (checked against the file as it is)."""
import subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
AS = ["mips-linux-gnu-as", "-march=vr4300", "-mabi=32", "-EB", "-Iinclude", "-G0", "--defsym", "__ASSEMBLER__=1"]


def rows():
    out = []
    for l in (ROOT / "config" / "overlays.txt").read_text().split("\n"):
        if l.strip():
            i, v, t, d, r, b, n = l.split()
            f = next((ROOT / "extracted").glob(f"{i}_*.bin"))
            out.append((i, f, int(t, 16), int(d, 16), int(r, 16), f.stat().st_size))
    return out


def run(i, f, text, data, ro, size):
    import struct
    foot = struct.unpack(">I", f.read_bytes()[-4:])[0]
    tail = size - foot  # header, relocations and footer
    b = ROOT / "build" / "overlays"
    b.mkdir(parents=True, exist_ok=True)
    sub = [f"      - [0x0, asm, text]", f"      - [{text:#x}, data, data]"]
    if tail > text + data:
        sub.append(f"      - [{text + data:#x}, rodata, rodata]")
    (b / f"{i}.yaml").write_text(f"""name: ovl{i}
options:
  basename: ovl{i}
  target_path: {f.relative_to(ROOT)}
  base_path: ../..
  platform: n64
  compiler: IDO
  endianness: big
  asm_path: asm/overlays/{i}
  src_path: src/overlays/{i}
  asset_path: build/overlays/{i}_assets
  build_path: build/overlays/{i}
  ld_script_path: build/overlays/{i}/ovl{i}.ld
  create_asm_dependencies: False
  find_file_boundaries: False
  use_legacy_include_asm: False
  undefined_funcs_auto_path: build/overlays/{i}/undefined_funcs_auto.txt
  undefined_syms_auto_path: build/overlays/{i}/undefined_syms_auto.txt
segments:
  - name: ovl{i}
    type: code
    start: 0x0
    vram: 0x80000000
    subsegments:
""" + "\n".join(sub) + f"\n  - [{tail:#x}]\n")
    r = subprocess.run(["splat", "split", str(b / f"{i}.yaml")], capture_output=True, text=True, cwd=ROOT)
    if r.returncode:
        return "SPLAT FAILED: " + (r.stderr.strip().splitlines() or ["?"])[-1][:100]
    objs = []
    for s in sorted((ROOT / "asm" / "overlays" / i).rglob("*.s")):
        o = b / i / (s.relative_to(ROOT).as_posix() + ".o")
        o.parent.mkdir(parents=True, exist_ok=True)
        subprocess.run(AS + [str(s), "-o", str(o)], check=True, cwd=ROOT)
    elf, out = b / i / f"ovl{i}.elf", b / i / f"ovl{i}.bin"
    ld = ["mips-linux-gnu-ld", "-EB", "-T", str(b / i / f"ovl{i}.ld"), "-T", str(b / i / "undefined_syms_auto.txt"),
          "-T", str(b / i / "undefined_funcs_auto.txt"), "--no-check-sections", "-o", str(elf)]
    r = subprocess.run(ld, capture_output=True, text=True, cwd=ROOT)
    if r.returncode:
        return "LINK FAILED: " + (r.stderr.strip().splitlines() or ["?"])[-1][:100]
    subprocess.run(["mips-linux-gnu-objcopy", "-O", "binary", str(elf), str(out)], check=True)
    return "IDENTICAL" if out.read_bytes() == f.read_bytes()[:tail] else "DIFFERENT"


def main():
    args = sys.argv[1:]
    rs = rows()
    if "--smallest" in args:
        n = int(args[args.index("--smallest") + 1])
        rs = sorted(rs, key=lambda r: r[5])[:n]
    elif args:
        rs = [r for r in rs if r[0] in args]
    ok = 0
    for i, f, t, d, r, size in rs:
        res = run(i, f, t, d, r, size)
        ok += res == "IDENTICAL"
        print(f"{i} {size:#x}: {res}", flush=True)
    print(f"{ok} / {len(rs)} overlays rebuild identical")


if __name__ == "__main__":
    main()
