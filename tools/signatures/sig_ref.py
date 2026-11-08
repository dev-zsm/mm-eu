#!/usr/bin/env python3
"""Prototypes of the overlay functions that the reference decompilation knows, as a table for retype.py and sig_header.py. Run in WSL.
usage: sig_ref.py [--ref DIR] [--stats]       writes config/overlays/protos.txt (input of tools/signatures/retype.py, read by sig_header.py)
Table line (the format of retype.py):  ovlNNNN <function> generated/overlays/NNNN.h <prototype>   # <evidence>
Which functions, and from where:
  - a function named in config/overlays/names.txt with the evidence "bytes identical": its prototype is the one of the reference function of
    that name (the definition in the reference source of the same overlay; a function imported by tools/search/ref_import.py carries it
    in its own file, with the reference's name or `ref_func_XXXXXXXX` for a function the reference has not named);
  - a function that sig_header_flow derives from the calls of the overlay (`derive`, see below).
The reference spells types that the generated header cannot (a structure of the reference, an enum, `Gfx**`): a pointer to such a type is
`void *`; a pointer to a basic type, to `Actor`, `PlayState`, `Vec3f`, `Vec3s` or to the structure of the actor of the overlay (`EnTest` for
`EnTest_Init`) is kept; an unknown type that is not a pointer (an enum, a structure passed by value) makes the function skipped, as does a
function pointer. Parameter names are the reference's. Nothing is invented: a function without a prototype of the reference keeps the
reading of its assembly. The result is applied by `retype.py config/overlays/protos.txt` (a definition changes only if it still compiles to the
ROM's bytes) and by `sig_header.py overlays --apply`; `prune` drops what the check refused."""
import functools, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import retype  # noqa: E402
import sig_header  # noqa: E402
import srcpath  # noqa: E402

TABLE = ROOT / "config" / "overlays" / "protos.txt"
DEF = re.compile(r"^(?:static\s+)?(?:inline\s+)?(?P<ret>(?:const\s+)?[A-Za-z_]\w*(?:\s*\*+\s*|[ \t]+))(?P<name>[A-Za-z_]\w*)\s*"
                 r"\((?P<args>[^;{}()]*)\)\s*\{", re.M)
SCALARS = {"s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64", "char", "short", "int", "long", "float", "double"}
WANT = {"Actor *", "PlayState *"}   # the types a parameter takes from the caller that passes it on (and the actor structure)
ALIAS = {"bool": "s32"}   # stdbool.h of the reference: an int
NOT_NAMES = {"if", "while", "for", "switch", "return", "else", "sizeof"}


def definitions(text: str) -> dict:
    """{name: (return type, argument text)} of the functions defined at the left margin of a C file."""
    return {m.group("name"): (" ".join(m.group("ret").split()), " ".join(m.group("args").split()))
            for m in DEF.finditer(text) if m.group("name") not in NOT_NAMES and m.group("ret").split()[0] not in NOT_NAMES}


def conv(t: str, structs: set):
    """Our spelling of a type of the reference, or None when the header cannot say it."""
    t = re.sub(r"\b(const|volatile|register|static)\b", "", t)
    stars = t.count("*")
    base = " ".join(t.replace("*", " ").split())
    base = ALIAS.get(base, base)
    if stars == 0:
        return base if base in SCALARS or base == "void" else None
    if stars == 1 and (base in SCALARS or base in sig_header.VOCAB or base in structs):
        return base + " *"
    return "void *"


def proto(fn: str, ret: str, args: str, structs: set):
    """`ret fn(args)` in our types, or None."""
    r = conv(ret, structs)
    if r is None:
        return None
    out = []
    if args.strip() not in ("", "void"):
        for k, a in enumerate(x.strip() for x in args.split(",")):
            m = re.match(r"^(?P<type>.*?[\s\*])(?P<name>\w+)$", a)
            if "(" in a or a == "..." or not m or not m.group("type").strip():
                return None
            t = conv(m.group("type"), structs)
            if t is None or t == "void":
                return None
            out.append(f"{t}{'' if t.endswith('*') else ' '}{m.group('name')}")
    return f"{r}{'' if r.endswith('*') else ' '}{fn}({', '.join(out) or 'void'})"


def imported_definitions(seg: str, fns) -> dict:
    """{our function: (reference name, return type, arguments)} read from the files that tools/search/ref_import.py wrote."""
    nm = sig_header.names.load(seg)
    out = {}
    for fn in fns:
        path = srcpath.overlay_dir(seg[3:]) / f"{fn}.c"
        if not path.exists() or "generated/mm/" not in path.read_text():
            continue
        defs = definitions(path.read_text())
        name = nm.get(fn) if nm.get(fn) in defs else (next(iter(defs)) if len(defs) == 1 else None)
        if name:
            out[fn] = (name, *defs[name])
    return out


def reference_index(ref: Path):
    """{folder: {name: [(ret, args)]}} of the functions defined in the overlay files of the reference."""
    out = {}
    for f in sorted((ref / "src" / "overlays").rglob("*.c")):
        if f.name.endswith(".inc.c"):
            continue
        d = out.setdefault(f.parent.name, {})
        for name, v in definitions(f.read_text(errors="replace")).items():
            d.setdefault(name, []).append(v)
    return out


NO_DEST = sig_header.STORE | {"swc1", "sdc1", "mtc1", "dmtc1", "nop", "mult", "multu", "div", "divu", "jr", "jalr", "jal", "break"}
TEMPS = {"v0", "v1", "at", "a0", "a1", "a2", "a3", *(f"t{i}" for i in range(10))}


LINE = re.compile(r"/\*\s+\w+\s+8[0-9A-F]{7}\s+([0-9A-F]{8})\s*\*/\s+(\w[\w.]*)\s*(.*?)\s*(?:#.*)?$")


def parse(chunk: str):
    """[(mnemonic, operands, instruction word)] of the disassembly of one function."""
    return [(m.group(2), [o.strip() for o in m.group(3).split(",")] if m.group(3) else [], int(m.group(1), 16))
            for m in map(LINE.search, chunk.split("\n")) if m]


def load_base(seg: str, chunks):
    """The distance between the address the overlay was linked at and 0x80000000, where its functions are read (its `jal` hold the linked address): the one for which
    most targets of the `jal` of the overlay are the start of one of its functions. None when two are as good."""
    starts = {int(fn[5:], 16) for fn, _ in chunks}
    targets = [((w & 0x3FFFFFF) << 2) | 0x80000000 for _, c in chunks for mn, _, w in parse(c) if mn == "jal"]
    distinct = sorted(set(targets))
    probes = distinct[:2] + distinct[len(distinct) // 2:len(distinct) // 2 + 1] + distinct[-2:]   # a few targets are enough to propose the bases
    bases = {t - s for t in probes for s in starts if (t - s) % 16 == 0 and t - s > 0}
    score = {b: sum(t - b in starts for t in targets) for b in bases}
    top = sorted(score.values(), reverse=True)[:2] + [0]
    best = [b for b, v in score.items() if v == top[0]]
    return best[0] if len(best) == 1 and top[0] > top[1] and top[0] >= 3 else None


HI = re.compile(r"%hi\((func_[0-9A-F]{8})\)")
LO = re.compile(r"%lo\((func_[0-9A-F]{8})\)")
MEM = re.compile(r"^(-?(?:0x)?[0-9A-Fa-f]+)\(\$(\w+)\)$")


def trace(ins):
    """(calls, pointer calls, stores) of one function, following the straight line of the code (not the branches). A register holds one of
    ("p", j): the parameter j of the function, untouched (copied by `move`, or kept in a slot of the stack above the argument area and
    loaded back); ("f", address): the address of a function (`lui`/`addiu` of %hi/%lo(func_XXXXXXXX)); ("m", off, j): the word at
    `off` in the structure the parameter j points to. calls: [(callee address, {k: value of a<k>})] (callee 0 for an unknown target);
    pointer calls: [(off, j, {k: value})], a call through a word loaded from the structure of the parameter j; stores: [(off, j, value)],
    a word stored into the structure of the parameter j."""
    val = {f"a{k}": ("p", k) for k in range(4)}
    hi, spill, calls, pcalls, stores = {}, {}, [], [], []
    pend = None   # the call whose delay slot is next
    for mn, ops, word in ins:
        regs = [r for o in ops for r in sig_header.REG.findall(o)]
        mem = MEM.match(ops[-1].strip()) if ops else None
        if mn == "lw" and mem and len(regs) == 2:
            off, b = int(mem.group(1), 16 if "0x" not in mem.group(1) else 0), mem.group(2)
            v = spill.get(off) if b == "sp" else ("m", off, val[b][1]) if val.get(b, ("",))[0] == "p" else None
            val.pop(regs[0], None)
            if v:
                val[regs[0]] = v
            hi.pop(regs[0], None)
        elif mn == "sw" and mem and len(regs) == 2:
            off, b = int(mem.group(1), 16 if "0x" not in mem.group(1) else 0), mem.group(2)
            v = val.get(regs[0])
            if b == "sp":
                spill.pop(off, None)
                if v and off >= 0x10:
                    spill[off] = v
            elif v and val.get(b, ("",))[0] == "p":
                stores.append((off, val[b][1], v))
        elif mn == "lui" and regs:
            val.pop(regs[0], None)
            m = HI.search(ops[-1])
            hi.pop(regs[0], None)
            if m:
                hi[regs[0]] = m.group(1)
        elif mn == "addiu" and len(regs) == 2 and LO.search(ops[-1]) and hi.get(regs[1]) == LO.search(ops[-1]).group(1):
            val[regs[0]] = ("f", int(hi[regs[1]][5:], 16))
            hi.pop(regs[0], None)
        elif mn not in NO_DEST and not mn.startswith(("b", "j", "c.")) and regs:
            d = regs[0]
            src = None
            if mn in ("or", "addu") and len(regs) == 3 and "zero" in regs[1:]:
                src = next((r for r in regs[1:] if r != "zero"), None)
            elif mn == "addiu" and len(regs) == 2 and ops[-1].strip() == "0":
                src = regs[1]
            v = val.get(src)
            val.pop(d, None)
            hi.pop(d, None)
            if v:
                val[d] = v
        if pend is not None:   # the delay slot has run: the call takes place
            args = {k: val[f"a{k}"] for k in range(4) if f"a{k}" in val}
            if pend[0] == "m":
                pcalls.append((pend[1], pend[2], args))
            elif pend[0] == "d":
                calls.append((pend[1], args))
            else:
                calls.append((0, args))
            for r in TEMPS:
                val.pop(r, None)
                hi.pop(r, None)
            for off in [o for o in spill if o < 0x10]:   # the callee keeps its own arguments there
                del spill[off]
            pend = None
        if mn == "jal":
            pend = ("d", ((word & 0x3FFFFFF) << 2) | 0x80000000)
        elif mn == "jalr":
            v = val.get(regs[-1]) if regs else None
            pend = ("m", v[1], v[2]) if v and v[0] == "m" else ("d", v[1]) if v and v[0] == "f" else ("x",)
    return calls, pcalls, stores


def flows(ins):
    """[(callee target, {k: j})]: for each direct call of a function, the arguments a<k> that hold, untouched, the parameter j of the caller."""
    return [(t, {k: v[1] for k, v in a.items() if v[0] == "p"}) for t, a in trace(ins)[0] if t]


@functools.lru_cache(maxsize=None)
def guessed(seg: str) -> dict:
    """The prototypes read from the assembly alone, without the table: {real name: (function, line)}."""
    sig_header.USE_PROTOS = False
    sig_header.proto_table.cache_clear()
    try:
        return sig_header.build(seg)
    finally:
        sig_header.USE_PROTOS = True
        sig_header.proto_table.cache_clear()


def agrees(seg: str, fn: str, proto_text: str) -> bool:
    """Whether the assembly of `fn` agrees with a prototype: at least as many parameters as it reads, a float where it reads one,
    no scalar where it uses the register as the base of a load or store."""
    for real, (f, line) in guessed(seg).items():
        if f == fn:
            m = re.match(r"^.*?[\s\*]" + re.escape(real) + r"\((?P<args>.*)\);", line)
            old, new = retype.params(m.group("args")) if m else None, retype.params(proto_text.split("(", 1)[1].rsplit(")", 1)[0])
            if old is None or new is None or len(new) < len(old):
                return False
            for (ot, _), (nt, _) in zip(old, new):
                if (ot in ("f32", "f64") and nt != ot) or ("*" in ot and ("*" not in nt or nt in ("f32", "f64"))):
                    return False
            return True
    return False


def derive(seg: str, known: dict, structs: set):
    """{function: prototype} for the functions of the overlay that receive, untouched and at every call, a parameter of a function whose
    types are known (the handlers, the functions of the reference): `Actor *thisx` from the handler is the actor itself (`EnTest *this` in
    the helpers), `PlayState *play` is the play state. `known` is {function: prototype}; the others keep the reading of their assembly
    for the parameters that do not receive one."""
    guess = guessed(seg)
    cur = {}   # our function -> (return type, [(type, name)])
    for real, (fn, line) in guess.items():
        m = re.match(r"^(?P<ret>.*?[\s\*])" + re.escape(real) + r"\((?P<args>.*)\);", line)
        ps = retype.params(m.group("args")) if m else None
        if ps is not None:
            cur[fn] = (m.group("ret").strip(), ps)
    for fn, p in known.items():
        m = re.match(r"^(?P<ret>.*?[\s\*])" + re.escape(fn) + r"\((?P<args>.*)\)$", p)
        ps = retype.params(m.group("args")) if m else None
        if ps is not None:
            cur[fn] = (m.group("ret").strip(), ps)
    typed = {fn: {k: t for k, (t, _) in enumerate(cur[fn][1]) if t in WANT or t.rstrip("* ") in structs} for fn in known if fn in cur}
    calls = []   # (caller, callee, {k: j})
    chunks = list(sig_header.chunks(seg))
    base = load_base(seg, chunks)
    if base is None:
        return {}
    name = lambda t: f"func_{t - base:08X}"  # noqa: E731
    tr = {fn: trace(parse(c)) for fn, c in chunks}
    # the functions stored in a word of the structure of the actor (`this->actionFunc = f`, or `SetupAction(this, f)` that stores its
    # second parameter there), and the calls through that word: the stored functions are called with the arguments of the call
    stored, param_store = {}, {}   # offset -> set of functions; function -> {parameter k: offset}
    for fn, (_, _, stores) in tr.items():
        for off, j, v in stores:
            if j == 0 and v[0] == "f":
                stored.setdefault(off, set()).add(name(v[1]))
            elif j == 0 and v[0] == "p":
                param_store.setdefault(fn, {})[v[1]] = off
    for fn, (cs, pcs, _) in tr.items():
        for t, args in cs:
            for k, v in args.items():
                off = param_store.get(name(t), {}).get(k) if t else None
                if v[0] == "f" and off is not None:
                    stored.setdefault(off, set()).add(name(v[1]))
        for t, args in cs:
            if t:
                calls.append((fn, name(t), {k: v[1] for k, v in args.items() if v[0] == "p"}))
        for off, j, args in pcs:
            if j == 0:
                for target in sorted(stored.get(off, ())):
                    calls.append((fn, target, {k: v[1] for k, v in args.items() if v[0] == "p"}))
    derived = {}
    for _ in range(6):
        seen = {}   # (callee, k) -> set of the types its call sites give (None: not a typed parameter)
        for caller, callee, args in calls:
            if callee not in cur or callee in known:
                continue
            for k in range(len(cur[callee][1])):
                j = args.get(k)
                t = (typed.get(caller, {}).get(j) if j is not None else None)
                seen.setdefault((callee, k), set()).add(t)
        changed = False
        for (callee, k), ts in seen.items():
            if len(ts) == 1 and None not in ts and typed.get(callee, {}).get(k) is None:
                typed.setdefault(callee, {})[k] = next(iter(ts))
                derived[callee] = True
                changed = True
        if not changed:
            break
    out = {}
    for fn in derived:
        ret, ps = cur[fn]
        ps = ps + [("s32", f"arg{k}") for k in range(len(ps), max(typed[fn]) + 1)]   # every caller passes it, the function may not read it
        new, used = [], set()
        for k, (t, n) in enumerate(ps):
            if k in typed[fn]:
                t = typed[fn][k]
                if t == "Actor *" and k == 0 and structs:
                    t = sorted(structs)[0] + " *"
                n = "this" if t.rstrip("* ") in structs else {"Actor *": "thisx", "PlayState *": "play"}.get(t, f"arg{k}")
                if n in used:
                    n = f"{n}{k}"
            used.add(n)
            new.append(f"{t}{'' if t.endswith('*') else ' '}{n}")
        out[fn] = f"{ret}{'' if ret.endswith('*') else ' '}{fn}({', '.join(new)})"
    return out


def generate(ref: Path):
    rows, stats = [], {}
    actors = {l.split()[0]: l.split()[1] for l in (ROOT / "config/overlays/actors.txt").read_text().splitlines()
              if l.strip() and not l.startswith("#")}
    index = reference_index(ref) if (ref / "src" / "overlays").exists() else {}
    already = set()   # handlers: config/overlays/signatures.txt types them
    for l in (ROOT / "config/overlays/signatures.txt").read_text().splitlines():
        already.add(tuple(l.split()[:2]))
    ident, weak = {}, set()   # (overlay, our function) -> reference name; weak: named by rank and size, not by identical bytes
    for line in (ROOT / "config/overlays/names.txt").read_text().splitlines():
        parts = line.split("#", 1)[0].split()
        if len(parts) == 3:
            ident[(parts[0], parts[1])] = parts[2]
            if "bytes identical" not in line:
                weak.add((parts[0], parts[1]))
    for line in (ROOT / "config/overlays/list.txt").read_text().splitlines():
        if not line.strip():
            continue
        idx = line.split()[0]
        seg = f"ovl{idx}"
        structs = sig_header.struct_names(seg)
        fns = sorted({fn for (i, fn) in ident if i == idx} | {p.stem for p in srcpath.overlay_dir(idx).glob("func_*.c")})
        found = imported_definitions(seg, fns)   # the reference's own definition, which compiled to the bytes of the ROM
        folder = f"ovl_{actors[idx]}" if idx in actors else None
        for fn in fns:
            if fn in found or (idx, fn) not in ident:
                continue
            cands = index.get(folder, {}).get(ident[(idx, fn)], []) if folder else []
            if len(cands) == 1:
                found[fn] = (ident[(idx, fn)], *cands[0])
        for fn in fns:
            if (seg, fn) in already:
                continue
            if fn not in found:
                if (idx, fn) in ident:
                    stats["no reference definition"] = stats.get("no reference definition", 0) + 1
                continue
            name, ret, args = found[fn]
            p = proto(fn, ret, args, structs)
            if p is None:
                stats["type the header cannot say"] = stats.get("type the header cannot say", 0) + 1
                continue
            rows.append(f"{seg} {fn} {sig_header.header_name(seg)} {p}   # ref: {name}({args})\n")
            stats["prototypes"] = stats.get("prototypes", 0) + 1
        mine = [r for r in rows if r.startswith(seg + " ")]
        known = {r.split()[1]: r.split(None, 3)[3].split("#")[0].strip() for r in mine}
        for l in (ROOT / "config/overlays/signatures.txt").read_text().splitlines():
            if l.startswith(seg + " "):
                known[l.split()[1]] = l.split(None, 3)[3].split("#")[0].strip()
        for fn, p in sorted(derive(seg, known, structs).items()):
            rows.append(f"{seg} {fn} {sig_header.header_name(seg)} {p}   # derived: the parameters are passed on untouched by every caller in the overlay\n")
            stats["derived"] = stats.get("derived", 0) + 1
    return rows, stats


def prune() -> int:
    """Drop from the table the lines that a file refused: `sig_header.py overlays --apply` lists in build/sig_refused.txt the files that
    included the header and no longer match it. Each is blamed on its own line and on the lines of the functions it names (a caller that
    passes fewer arguments than the prototype has, a type that conflicts with its own declaration). Returns the number of lines dropped."""
    refused = ROOT / "build" / "sig_refused.txt"
    lines = TABLE.read_text().splitlines(keepends=True)
    drop = set()
    for r in refused.read_text().splitlines() if refused.exists() else []:
        seg, fn, why = r.split(None, 2)
        if "no longer matches the header" not in why:
            continue
        text = srcpath.overlay_dir(seg[3:]).joinpath(f"{fn}.c").read_text()
        nm = sig_header.names.load(seg)
        words = set(re.findall(r"\w+", text))
        for i, l in enumerate(lines):
            f = l.split()[:2]
            if len(f) == 2 and f[0] == seg and (f[1] == fn or f[1] in words or nm.get(f[1]) in words):
                drop.add(i)
    TABLE.write_text("".join(l for i, l in enumerate(lines) if i not in drop))
    return len(drop)


def main():
    if "prune" in sys.argv:
        print(f"{prune()} lines dropped")
        return
    ref = Path(sys.argv[sys.argv.index("--ref") + 1]) if "--ref" in sys.argv else ROOT / "build" / "ref" / "mm"
    rows, stats = generate(ref)
    if "--stats" not in sys.argv:
        TABLE.write_text("# Prototypes of overlay functions, from the reference (tools/signatures/sig_ref.py): same format as signatures.txt\n" + "".join(rows))
    print(stats)


if __name__ == "__main__":
    main()
