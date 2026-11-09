"""Jump tables (switch) of the splat assembly: the table of a function, its case targets, and the fragments splat cut off the function.

IDO puts the case bodies after the first `jr $ra` of a function, and splat ends a function at every `jr $ra` that no branch jumps over, so a
`switch` whose bodies all return is split into a head (up to the first `jr $ra`) and fragments (the case bodies, each its own `nonmatching`
chunk). The real function is the head and the fragments up to the last case; `merge_chunks.py` joins them in the assembly, `config/<seg>/merged.txt`
lists them. A fragment is a chunk the jump table points to (or that follows one and that nothing else references)."""
import functools, re, struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CHUNK = re.compile(r"(?=^nonmatching )", re.M)
HEAD = re.compile(r"nonmatching (\w+), (0x[0-9A-Fa-f]+)")
JTBL_USE = re.compile(r"%hi\((jtbl_[0-9A-Fa-f]{8})\)")
SEGBASE = {"boot": 0x80080000, "code": 0x800A5FE0}


def asm_path(seg):
    return ROOT / (f"asm/overlays/{seg[3:]}/text.s" if seg.startswith("ovl") else f"asm/{seg}/text.s")


def seg_file(seg):
    """(path of the segment bytes, address of its first byte); an overlay is read at 0x80000000 + offset."""
    if seg.startswith("ovl"):
        return next((ROOT / "extracted").glob(f"{seg[3:]}_*.bin")), 0x80000000
    return (ROOT / "build/boot.bin" if seg == "boot" else ROOT / "extracted/0049_00C8A000.bin"), SEGBASE[seg]


@functools.lru_cache(maxsize=None)
def chunks(seg):
    """[(name, address, size, text)] of the functions of the segment, in address order."""
    out = []
    for ch in CHUNK.split(asm_path(seg).read_text())[1:]:
        m = HEAD.match(ch)
        if m:
            out.append((m.group(1), int(m.group(1)[-8:], 16), int(m.group(2), 16), ch))
    return out


def text_len(seg):
    """Size of the code of an overlay: the first section; a code or boot segment is cut at its data (see the chunks)."""
    c = chunks(seg)
    return c[-1][1] + c[-1][2] - c[0][1]


@functools.lru_cache(maxsize=None)
def link_base(seg):
    """Overlay: the address the file was linked at (the `jal`s and the tables hold it, the relocation table corrects them at load). It is the base b
    for which every `jal` target that lands in the file is the start of a function; None for boot and code (linked where they run)."""
    if not seg.startswith("ovl"):
        return None
    starts = {a - 0x80000000 for _, a, _, _ in chunks(seg)}
    cand = set()
    for _, _, _, t in chunks(seg):
        cand.update(int(x, 16) for x in re.findall(r"\bjal\s+func_([0-9A-Fa-f]{8})", t))
    cand = {c for c in cand if c >= 0x80200000}
    best = (0, None)
    for t in sorted(cand)[:4]:
        for s in starts:
            b = t - s
            if b & 0xF:
                continue
            ok = sum(1 for x in cand if x - b in starts)
            if ok > best[0]:
                best = (ok, b)
    return best[1]


def to_off(seg, addr):
    """File offset of an address as the code of the segment holds it (overlay: link address)."""
    if seg.startswith("ovl"):
        return addr - link_base(seg)
    return addr - SEGBASE[seg]


def vram(seg, addr):
    """The address splat uses for what a table entry points to (overlay: 0x80000000 + offset)."""
    return 0x80000000 + (addr - link_base(seg)) if seg.startswith("ovl") else addr


def table(seg, label, count=None):
    """(entries as splat addresses, address of the table as the code holds it) of `jtbl_XXXXXXXX`; the entry count is the bound of the compare
    before the jump when given, else the size of the table symbol in the data file (boot, code)."""
    addr = int(label[-8:], 16)
    path, _ = seg_file(seg)
    data = _bytes(str(path))
    off = to_off(seg, addr)
    if count is None:
        count = _table_size(seg, label)
    ents = [struct.unpack_from(">I", data, off + 4 * i)[0] for i in range(count)]
    return [vram(seg, e) for e in ents], addr


@functools.lru_cache(maxsize=None)
def _bytes(path):
    return Path(path).read_bytes()


@functools.lru_cache(maxsize=None)
def _sizes_of_tables(seg):
    out = {}
    p = ROOT / "asm" / seg / "data" / "data.data.s"
    if not p.exists():
        return out
    cur = None
    for line in p.read_text().splitlines():
        m = re.match(r"dlabel (jtbl_[0-9A-Fa-f]{8})", line)
        if m:
            cur = m.group(1)
            out[cur] = 0
        elif cur and line.lstrip().startswith("/*") and ".word" in line:
            out[cur] += 1
        elif line.startswith("enddlabel"):
            cur = None
    return out


def _table_size(seg, label):
    return _sizes_of_tables(seg)[label]


def bound(text, label):
    """Entry count of the table `label` used in `text`: the `sltiu $at, reg, N` that guards the jump (N cases)."""
    i = text.find(f"%hi({label})")
    pre = text[:i].splitlines()
    for line in reversed(pre):
        m = re.search(r"sltiu\s+\$at, \$\w+, (0x[0-9A-Fa-f]+|\d+)", line)
        if m:
            return int(m.group(1), 0)
    return None


def head_tables(seg, name):
    """[(label, entries)] of the tables the function reads (entries as splat addresses)."""
    ch = next(c for c in chunks(seg) if c[0] == name)
    res = []
    for lab in dict.fromkeys(JTBL_USE.findall(ch[3])):
        n = bound(ch[3], lab)
        if n is None and lab in _sizes_of_tables(seg):
            n = _table_size(seg, lab)
        if n is None:
            continue
        res.append((lab, table(seg, lab, n)[0]))
    return res


@functools.lru_cache(maxsize=None)
def referenced(seg):
    """Addresses (splat style) that something other than a jump table points to: jal targets, function pointers in data, calls from other
    segments are not seen (a function of the code segment called only by overlays would look unreferenced: callers() checks the overlays)."""
    refs = set()
    for _, _, _, t in chunks(seg):
        for x in re.findall(r"\bjal\s+func_([0-9A-Fa-f]{8})", t):
            a = int(x, 16)
            refs.add(vram(seg, a) if seg.startswith("ovl") and a >= 0x80200000 else a)
    return refs


def fragments(seg, name):
    """(fragment names, end address of the longest plausible span) of the function: the chunks after it that its tables point to, plus the chunks
    that follow the last of them and nothing but fall-through reaches (they are listed as `maybe`, see `spans`)."""
    cs = chunks(seg)
    idx = next(i for i, c in enumerate(cs) if c[0] == name)
    head = cs[idx]
    tabs = head_tables(seg, name)
    targets = {e for _, ents in tabs for e in ents}
    end = head[1] + head[2]
    frags = []
    for c in cs[idx + 1:]:
        if c[1] != end:
            break
        if c[1] in targets and c[1] not in referenced(seg):
            frags.append(c[0])
            end = c[1] + c[2]
        else:
            break
    return frags, end


def spans(seg, name):
    """Possible ends of the function, shortest first: after the last chunk the tables point to, then after each unreferenced chunk that follows
    (a default or a tail that is not in a table). Each is an address; the C size decides."""
    cs = chunks(seg)
    idx = next(i for i, c in enumerate(cs) if c[0] == name)
    tabs = head_tables(seg, name)
    targets = {e for _, ents in tabs for e in ents}
    last = max([t for t in targets if t >= cs[idx][1]] or [cs[idx][1]])
    out, end = [], cs[idx][1] + cs[idx][2]
    for c in cs[idx + 1:]:
        if c[1] != end:
            break
        if c[1] in referenced(seg) and c[1] not in targets:
            break
        end = c[1] + c[2]
        if c[1] >= last:
            out.append(end)
    return out


@functools.lru_cache(maxsize=8192)
def object_tables(path):
    """[(offset in .rodata, word)] of the words of an ELF32 big-endian object's .rodata that a relocation against .text fills: the case targets of
    its jump tables, as offsets in .text (the word holds the addend). In offset order."""
    d = Path(path).read_bytes()
    shoff, = struct.unpack_from(">I", d, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from(">HHH", d, 0x2E)
    secs = [struct.unpack_from(">10I", d, shoff + i * shentsize) for i in range(shnum)]
    shstr = secs[shstrndx][4]

    def cstr(base, o):
        return d[base + o:d.index(b"\0", base + o)].decode()

    names = [cstr(shstr, s[0]) for s in secs]
    if ".rodata" not in names:
        return []
    ri = names.index(".rodata")
    out = []
    for s in secs:
        if s[1] == 9 and s[7] == ri:   # SHT_REL of .rodata
            for k in range(s[5] // 8):
                off, info = struct.unpack_from(">II", d, s[4] + 8 * k)
                if info & 255 == 2:   # R_MIPS_32
                    out.append((off, struct.unpack_from(">I", d, secs[ri][4] + off)[0]))
    return sorted(out)


def tables_agree(obj_words, func_start, tables, func_addr):
    """Does every ROM table (list of entry addresses) appear, as offsets from the function start, as a run of consecutive words among the
    relocated words of our .rodata (`object_tables`)? `func_start` is the offset of the function in our .text."""
    for ents in tables:
        want = [e - func_addr + func_start for e in ents]
        words = [w for _, w in obj_words]
        offs = [o for o, _ in obj_words]
        if not any(words[i:i + len(want)] == want and offs[i + len(want) - 1] - offs[i] == 4 * (len(want) - 1)
                   for i in range(len(words) - len(want) + 1)):
            return False
    return True
