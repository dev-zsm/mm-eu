#!/usr/bin/env python3
"""Rebuild one code segment from per-function objects: C (IDO 7.1) where src/<seg>/<fn>.c exists,
the splat assembly otherwise. Links them at the original addresses and compares with the ROM bytes.
Run in WSL.  usage: build_seg.py <boot|code> <original.bin>"""
import re, shutil, struct, subprocess, sys, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CC = ROOT / "tools/vendor/ido71/cc"
DEFAULT_FLAGS = ["-O2", "-g3", "-mips2"]
CFLAGS = ["-G", "0", "-non_shared", "-Xcpluscomm", "-w", "-I" + str(ROOT / "include")]
AS = ["mips-linux-gnu-as", "-march=vr4300", "-mabi=32", "-EB", "-I" + str(ROOT / "include"), "-G0"]
HDR = '.include "macro.inc"\n.set noat\n.set noreorder\n.set gp=64\n.section .text, "ax"\n'
sys.path.insert(0, str(Path(__file__).resolve().parent))
import names as _names  # noqa: E402

LBL = re.compile(r"\.L[0-9A-Fa-f]{8}")


def sh(*a):
    return subprocess.run(a, check=True, capture_output=True, text=True).stdout


def trim_text(obj: Path, size: int, section: bytes = b".text") -> int:
    """Cut a section (.text by default) of an ELF32 big-endian object to at most `size` bytes (alignment 4), return
    its new size. Both IDO and GNU as pad sections to 16 bytes, but the ROM function or constant pool is not padded."""
    d = bytearray(obj.read_bytes())
    struct.pack_into(">I", d, 0x24, 0x20001101)  # same e_flags as GNU as output, else ld refuses mips2/mips3 mixes
    shoff, = struct.unpack_from(">I", d, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from(">HHH", d, 0x2E)
    sec = lambda i: shoff + i * shentsize
    stroff = struct.unpack_from(">I", d, sec(shstrndx) + 16)[0]
    for i in range(shnum):
        name = struct.unpack_from(">I", d, sec(i))[0]
        if d[stroff + name:stroff + name + len(section) + 1] == section + b"\0":
            off, cur = struct.unpack_from(">II", d, sec(i) + 16)
            new = min(cur, size)
            assert not any(d[off + new:off + cur]), f"{obj.name}: non-zero bytes beyond {new:#x}"
            struct.pack_into(">I", d, sec(i) + 20, new)
            struct.pack_into(">I", d, sec(i) + 32, 4)
            obj.write_bytes(d)
            return new
    raise SystemExit(f"no {section.decode()} in {obj}")


def main():
    seg, orig = sys.argv[1], Path(sys.argv[2])
    out = ROOT / "build" / seg
    objdir = out / "fn"
    objdir.mkdir(parents=True, exist_ok=True)
    cfg = (ROOT / "config" / f"{seg}.yaml").read_text()
    vram = int(re.search(r"vram: (0x[0-9A-Fa-f]+)", cfg).group(1), 16)
    text_end = vram + int(re.search(r"\[(0x[0-9A-Fa-f]+), data", cfg).group(1), 16)
    NM = _names.load(seg)
    chunks = re.split(r"(?=^nonmatching )", (ROOT / "asm" / seg / "text.s").read_text(), flags=re.M)[1:]
    names = [re.match(r"nonmatching (\w+)", c).group(1) for c in chunks]
    addrs = [int(n[-8:], 16) for n in names]
    foot = [b - a for a, b in zip(addrs, addrs[1:] + [text_end])]  # bytes from this symbol to the next

    # local labels (.Lxxxxxxxx) referenced from another chunk must become global symbols
    defs = {}
    for i, ch in enumerate(chunks):
        for m in re.finditer(r"^\s*(\.L[0-9A-Fa-f]{8}):", ch, re.M):
            defs[m.group(1)] = i
    cross = {l for i, ch in enumerate(chunks) for l in set(LBL.findall(ch)) if defs.get(l, i) != i}
    keep_asm = {defs[l] for l in cross}  # a C function cannot provide these labels

    dlines = (ROOT / "asm" / seg / "data" / "data.data.s").read_text().splitlines()
    dlabel = {m.group(1): i for i, l in enumerate(dlines) if (m := re.match(r"dlabel (\w+)$", l))}
    dorder = sorted(dlabel, key=dlabel.get)
    pools = []  # (first data line, end data line, object): C constant pools linked in place of those data lines

    script_objs, n_c, data_pending = [], 0, []
    for i, (name, ch) in enumerate(zip(names, chunks)):
        obj = objdir / f"{name}.o"
        cfile = ROOT / "src" / seg / f"{name}.c"
        if cfile.exists() and i not in keep_asm:
            m = re.match(r"// FLAGS: (.*)", cfile.read_text().splitlines()[0])
            flags = m.group(1).split() if m else DEFAULT_FLAGS
            with tempfile.TemporaryDirectory() as d:  # IDO cc mishandles -o paths containing spaces
                subprocess.run([str(CC), "-c", *flags, *CFLAGS, "-o", d + "/x.o", str(cfile)],
                               check=True, stderr=subprocess.DEVNULL)
                shutil.move(d + "/x.o", obj)
            # a C function with its own constant pool: its .rodata takes the place of the data items the original
            # code references (one contiguous run); any other case stays assembly until its data is migrated
            secs = {m.group(1): int(m.group(2), 16) for m in re.finditer(
                r"\s(\.(?:rodata|rdata|data|sdata|lit4|lit8))\s+([0-9a-f]+)", sh("mips-linux-gnu-objdump", "-h", str(obj)))}
            refs = sorted({dorder.index(r) for r in re.findall(r"%(?:hi|lo)\((\w+)\)", ch) if r in dlabel})
            if any(v for k, v in secs.items() if k != ".rodata") or (secs.get(".rodata") and (
                    not refs or refs != list(range(refs[0], refs[-1] + 1)) or refs[-1] + 1 >= len(dorder))):
                data_pending.append(name)
                cfile = None
            elif secs.get(".rodata"):
                first, nxt = dorder[refs[0]], dorder[refs[-1] + 1]
                size = int(nxt[-8:], 16) - int(first[-8:], 16)
                assert trim_text(obj, size, b".rodata") == size, f"{name}: constant pool smaller than {size:#x}"
                start = dlabel[first]
                while dlines[start - 1].startswith("nonmatching") or not dlines[start - 1].strip():
                    start -= 1
                end = dlabel[nxt]
                while dlines[end - 1].startswith((".align", "nonmatching")) or not dlines[end - 1].strip():
                    end -= 1
                pools.append((start, end, obj))
        if cfile is not None and cfile.exists() and i not in keep_asm:
            n_c += 1
        else:
            s = objdir / f"{name}.s"
            ch = _names.apply(ch, NM)
            body = LBL.sub(lambda m: "LX_" + m.group(0)[2:] if m.group(0) in cross else m.group(0), ch)
            exported = "".join(f".globl LX_{l[2:]}\n" for l in cross if defs[l] == i)
            s.write_text(HDR + exported + body)
            sh(*AS, str(s), "-o", str(obj))
        used = trim_text(obj, foot[i])
        script_objs.append(obj)
        if used < foot[i]:  # alignment padding between symbols belongs to no chunk: explicit zeros
            pad, ps = objdir / f"pad_{addrs[i]:08X}.o", objdir / f"pad_{addrs[i]:08X}.s"
            ps.write_text(HDR + f".space {foot[i] - used}\n")
            sh(*AS, str(ps), "-o", str(pad))
            trim_text(pad, foot[i] - used)
            script_objs.append(pad)

    # reuse splat's linker script, swapping the single text object for the per-function ones
    named = out / "named"
    named.mkdir(exist_ok=True)
    for f in ("undefined_syms_auto.txt", "undefined_funcs_auto.txt"):
        (named / f).write_text(_names.apply((out / f).read_text(), NM))
    al = ROOT / "config" / f"{seg}.aliases.txt"
    if al.exists():  # alias symbols that only exist to steer IDO while matching
        with (named / "undefined_syms_auto.txt").open("a") as f:
            for line in al.read_text().splitlines():
                if line.strip() and not line.startswith("#"):
                    a, addr = line.split()[:2]
                    f.write(f"{a} = {addr};\n")
    # the data file is split around the C constant pools: data_0.o(.data), pool.o(.rodata), data_1.o(.data), ...
    head = "\n".join(dlines[:next(i for i, l in enumerate(dlines) if l.startswith(".section")) + 1]) + "\n"
    data_parts, cur = [], 0
    for k, (a, b, pobj) in enumerate(sorted(pools, key=lambda t: t[0]) + [(len(dlines), len(dlines), None)]):
        ds = named / f"data_{k}.s"
        ds.write_text(_names.apply((head if k else "") + "\n".join(dlines[cur:a]) + "\n", NM))
        sh(*AS, str(ds), "-o", str(ds.with_suffix(".o")))
        data_parts.append(f"        {ds.with_suffix('.o').relative_to(ROOT)}(.data);")
        if pobj is not None:
            data_parts.append(f"        {pobj.relative_to(ROOT)}(.rodata);")
        cur = b
    ld = (out / f"{seg}.ld").read_text()
    script = []
    for l in ld.splitlines():
        if "data.data.s.o" in l:
            script += data_parts
        elif "/text.s.o(" not in l:
            script.append(l)
        elif "(.text)" in l:
            script += [f"        {o.relative_to(ROOT)}(.text);" for o in script_objs]
    # splat forces 16-byte alignment on every input section; per-function objects need 4
    (out / f"{seg}.fn.ld").write_text("\n".join(script).replace("SUBALIGN(16)", "SUBALIGN(4)", 1) + "\n")
    elf, binf = out / f"{seg}.fn.elf", out / f"{seg}.fn.bin"
    sh("mips-linux-gnu-ld", "-EB", "-T", str(out / f"{seg}.fn.ld"), "-T", str(named / "undefined_syms_auto.txt"),
       "-T", str(named / "undefined_funcs_auto.txt"), "--no-check-sections", "-o", str(elf))
    sh("mips-linux-gnu-objcopy", "-O", "binary", str(elf), str(binf))
    ok = binf.read_bytes() == orig.read_bytes()
    if data_pending:
        print(f"note: {len(data_pending)} verified C functions still built from asm (own constant pool): {' '.join(data_pending)}")
    print(f"{seg}: {n_c} C functions + {len(chunks) - n_c} asm -> {'IDENTICAL to ROM' if ok else 'DIFFERENT'} "
          f"({binf.stat().st_size:#x} vs {orig.stat().st_size:#x} bytes)")
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()
