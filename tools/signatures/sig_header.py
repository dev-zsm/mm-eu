#!/usr/bin/env python3
"""Prototypes of a whole segment in one header, then the sources use it. Run in WSL.
usage: sig_header.py <seg> [--apply] [-j N]          seg = boot, code or ovlNNNN (or `overlays`: every overlay)
  without --apply: write the header only (include/generated/<seg>_funcs.h, include/generated/overlays/NNNN.h) and report
  with --apply:   also make each verified C file include it and drop its own `extern` declarations of those functions;
                  a file is kept only if it still compiles to the exact bytes of the ROM (the others are restored)
Where a function has verified C, its prototype is the one of its definition (types the header knows only: the ones of types.h
and pointers to them). Where it has none, the prototype is read from the assembly: the arguments (registers read before they
are written, a callee's arguments counted when they are passed on untouched), pointers (used as the base of a load or store),
floats ($f12/$f14 read first) and the result (read by a caller after the call). Such an inferred prototype is only a
reading of the code, it never replaces a definition."""
import collections, functools, re, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import match  # noqa: E402
import names  # noqa: E402
import objcache  # noqa: E402
import retype  # noqa: E402
import srcpath  # noqa: E402
import tidy_perm  # noqa: E402

BASIC = {"void", "s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64", "char", "short", "int", "long",
         "unsigned", "signed", "float", "double", "const"}
LOAD = {"lw", "lh", "lhu", "lb", "lbu", "lwl", "lwr", "ll"}
STORE = {"sw", "sh", "sb", "swl", "swr", "sc"}
LINE = re.compile(r"\*/\s+(\w[\w.]*)\s*(.*?)\s*(?:#.*)?$")
REG = re.compile(r"\$(\w+)")
CLOBBER = {"a0", "a1", "a2", "a3", "v0", "v1", "at", *(f"t{i}" for i in range(10))} | {f"f{i}" for i in range(0, 20)}


def header_path(seg: str) -> Path:
    return ROOT / "include" / header_name(seg)


def header_name(seg: str) -> str:
    return "generated/overlays/" + seg[3:] + ".h" if seg.startswith("ovl") else f"generated/{seg}_funcs.h"


def chunks(seg: str):
    text = match.asm_file(seg).read_text()
    for c in re.split(r"(?=^nonmatching )", text, flags=re.M)[1:]:
        m = re.match(r"nonmatching (\w+), (0x[0-9A-Fa-f]+)", c)
        if m and c.split("\n", 2)[2].lstrip().startswith("glabel"):
            yield m.group(1), c


def parse(chunk: str):
    out = []
    for line in chunk.split("\n"):
        m = LINE.search(line)
        if m:
            out.append((m.group(1), [o.strip() for o in m.group(2).split(",")] if m.group(2) else []))
    return out


def is_call(mn):
    return mn in ("jal", "jalr")


def scan(ins, arity_of):
    """One pass over the instructions of a function: (arity, {param: 'f32'|'f64'}, pointer params, [(callee, instr index)])."""
    written, alias, params, floats, ptr, calls = set(), {}, 0, {}, set(), []
    for r in ("a0", "a1", "a2", "a3"):
        alias[r] = int(r[1])

    def rd(r, size="f32"):
        nonlocal params
        if r in written:
            return
        if r in ("a0", "a1", "a2", "a3"):
            params = max(params, int(r[1]) + 1)
        elif r in ("f12", "f14"):
            floats.setdefault(0 if r == "f12" else 1, size)

    def base(r):
        if r in alias:
            ptr.add(alias[r])

    pend = None
    for i, (mn, ops) in enumerate(ins):
        regs = [r for o in ops for r in REG.findall(o)]
        size = "f64" if mn.endswith(".d") or mn in ("ldc1", "sdc1") else "f32"
        if mn in LOAD or mn in ("lwc1", "ldc1"):
            b = regs[-1]
            rd(b)
            if b not in ("sp", "gp"):
                base(b)
            d = regs[0]
            written.add(d)
            alias.pop(d, None)
        elif mn in STORE or mn in ("swc1", "sdc1"):
            b = regs[-1]
            rd(b)
            if b not in ("sp", "gp"):
                base(b)
            rd(regs[0], size)
        elif mn in ("or", "addu", "addiu", "ori") and len(regs) >= 2 and (mn != "or" and mn != "addu" or "zero" in regs[1:]):
            src = next((r for r in regs[1:] if r != "zero"), None)
            if src:
                rd(src)
            d = regs[0]
            written.add(d)
            if src in alias:
                alias[d] = alias[src]
            else:
                alias.pop(d, None)
        elif mn.startswith(("beq", "bne")):
            for r in regs[:2]:
                rd(r)
        elif mn.startswith(("bgez", "bltz", "blez", "bgtz")):
            rd(regs[0])
        elif mn == "jal":
            callee = ops[0]
            pend = (callee, i)
        elif mn == "jalr":
            rd(regs[0])
            pend = (None, i)
        elif mn == "jr":
            rd(regs[0]) if regs[0] != "ra" else None
        elif mn in ("mtc1", "dmtc1"):
            rd(regs[0])
            written.add(regs[1])
        elif mn in ("mfc1", "dmfc1"):
            rd(regs[1], size)
            written.add(regs[0])
            alias.pop(regs[0], None)
        elif mn.startswith("c.") or mn in ("mult", "multu", "div", "divu"):
            for r in regs:
                rd(r, size)
        elif mn in ("mflo", "mfhi", "lui"):
            written.add(regs[0])
            alias.pop(regs[0], None)
        elif mn == "nop" or mn.startswith(("bc1", "b", "j", "break")):
            pass
        elif regs:   # three-operand or two-operand arithmetic / float ops: first is written, the others read
            for r in regs[1:]:
                rd(r, size)
            written.add(regs[0])
            alias.pop(regs[0], None)
        if pend and mn not in ("jal", "jalr") and (pend[1] == i - 1):   # the delay slot has run: the call takes place
            callee, at = pend
            if callee:
                k = arity_of(callee)
                for n in range(k):
                    rd(f"a{n}")
                calls.append((callee, at))
            for c in CLOBBER:
                written.add(c)
                alias.pop(c, None)
            pend = None
    return params, floats, ptr, calls


def result_uses(ins, at):
    """How a caller uses the result of the call at index `at`: 'int', 'ptr', 'f32', 'f64' or None (looks only a few instructions)."""
    seen = {}
    for mn, ops in ins[at + 2:at + 10]:
        regs = [r for o in ops for r in REG.findall(o)]
        if is_call(mn) or mn == "jr":
            if mn == "jr" and regs and regs[0] == "ra":
                return "int" if "v0" in seen.get("v0r", ()) else None
            break
        size = "f64" if mn.endswith(".d") or mn in ("sdc1",) else "f32"
        if mn in LOAD | STORE | {"lwc1", "swc1", "ldc1", "sdc1"} and regs[-1] == "v0":
            return "ptr"
        reads = regs[1:] if mn not in STORE | {"swc1", "sdc1", "mtc1"} and not mn.startswith(("beq", "bne", "c.")) else regs
        if mn in ("mtc1",):
            reads = regs[:1]
        if "v0" in reads:
            return "int"
        if "f0" in reads:
            return size
        if regs and regs[0] in ("v0", "f0") and mn not in STORE | {"swc1", "sdc1"}:
            return None
    return None


def definition(seg: str, fn: str, real: str):
    """(ret, params) of the verified C definition, None if there is none or it is not a plain prototype."""
    path = retype.source(seg, fn)
    if not path.exists():
        return None
    dm = re.search(r"^(?P<ret>[^\n;{}()]*?[\s\*])" + re.escape(real) + r"\((?P<args>[^)]*)\)\s*\{", path.read_text(), re.M)
    if not dm or "static" in dm.group("ret"):
        return None
    ret = " ".join(dm.group("ret").split()).replace("M2C_UNK", "s32")   # m2c_compat.h: typedef s32 M2C_UNK
    args = " ".join(dm.group("args").split()).replace("M2C_UNK", "s32")
    return ret, args


EXTERN = re.compile(r"^(?:extern\s+)?(?P<ret>(?:[A-Za-z_]\w*[\s\*]+)+)(?P<name>\w+)\s*\((?P<args>[^;{}()]*)\)\s*;", re.M)


def declared_in_sources(seg: str) -> dict:
    """{name: (ret, args)}: the `extern` declarations that the verified files of the segment already carry. They compile to the
    ROM's bytes, so they are better evidence of a function's prototype than the assembly alone."""
    base = srcpath.overlay_dir(seg[3:]) if seg.startswith("ovl") else ROOT / "src" / seg
    seen = {}   # name -> {(ret, args): how many files declare it so}
    for f in sorted(base.rglob("func_*.c")):
        if "wip" in f.parts:
            continue
        for m in EXTERN.finditer(f.read_text()):
            ret = " ".join(m.group("ret").split()).replace("M2C_UNK", "s32")
            if "static" in ret or "typedef" in ret or ret.startswith(("return", "else")):
                continue
            key = (ret, " ".join(m.group("args").split()).replace("M2C_UNK", "s32"))
            seen.setdefault(m.group("name"), collections.Counter())[key] += 1
    # the files disagree on some functions: the declaration most of them carry wins; on a tie, the one with more parameters
    # (a call with too many arguments is refused, one with too few is not)
    return {name: max(c, key=lambda k: (c[k], len([a for a in k[1].split(",") if a.strip()])))
            for name, c in seen.items()}


def type_known(ret: str, args: str) -> bool:
    ret, args = (re.sub(r"\b(?:struct|union) \w+\b", "void", x) for x in (ret, args))   # a tagged pointer needs no definition
    for decl in [ret] + ([a for a in args.split(",")] if args not in ("", "void") else []):
        words = re.findall(r"[A-Za-z_]\w*", decl)
        types = words if decl is ret else words[:-1]   # the last word of a parameter is its name
        if decl is not ret and len(words) == 1:
            types = words    # an unnamed parameter
        if any(w not in BASIC for w in types):
            return False
    return "(" not in args


SIGS = {}   # real name -> prototype, from config/<seg>/sigs.txt (tools/signatures/ref_sigs.py): the reference's own
SIGS_FIRST = False   # ref_sigs.py: the table beats the definitions, so that retyping a definition meets the prototype it will have
IMPORTED = {}   # real name -> address name of the functions written by ref_import.py: their lines are not ours to recompute
FROM_DEF = set()   # names whose prototype is the one of a definition (the others may keep the line already in the header)


def imported(seg: str, fn: str) -> bool:
    """A function written by tools/search/ref_import.py: its prototype is in the context header of its reference file, with the real types."""
    path = retype.source(seg, fn)
    return path.exists() and "generated/mm/" in path.read_text()


def build(seg: str):
    """{real name: (address name, prototype)} for every function of the segment."""
    nm = names.load(seg)
    sigs = ROOT / "config" / seg / "sigs.txt"
    SIGS.clear()
    if sigs.exists():
        SIGS.update({l.split(None, 1)[0]: l.split(None, 1)[1].split("  #")[0].strip() for l in sigs.read_text().splitlines()
                     if l.strip() and not l.startswith("#")})
    ext = declared_in_sources(seg)
    funcs = [(fn, parse(c)) for fn, c in chunks(seg)]
    known_arity = {}
    for fn, _ in funcs:
        d = definition(seg, fn, nm.get(fn, fn))
        if d and d[1] not in ("", "void") and "(" not in d[1]:
            known_arity[fn] = len([a for a in d[1].split(",") if a.strip()])
        elif d:
            known_arity[fn] = 0
    arity = dict.fromkeys((f for f, _ in funcs), 0)
    arity.update(known_arity)
    scans = {}
    for _ in range(3):   # a callee's arguments passed on untouched make the caller's arity grow: a few rounds settle it
        for fn, ins in funcs:
            if fn in known_arity:
                continue
            p, fl, ptr, calls = scan(ins, lambda c: arity.get(nm.get(c, c), arity.get(c, 0)))
            arity[fn] = p if not fl else max(p, 1)
            scans[fn] = (p, fl, ptr, calls)
    used = {}   # how callers use each callee's result
    for fn, ins in funcs:
        for callee, at in scan(ins, lambda c: arity.get(c, 0))[3]:
            u = result_uses(ins, at)
            if u:
                used.setdefault(callee, set()).add(u)
    out = {}
    for fn, ins in funcs:
        real = nm.get(fn, fn)
        if imported(seg, fn):
            IMPORTED[real] = fn
            continue   # no prototype of ours for it: the one inferred from the assembly would be worse than the reference's
        d = definition(seg, fn, real)
        if real in SIGS and (SIGS_FIRST or not d):
            out[real] = (fn, SIGS[real])
            FROM_DEF.add(real)   # the table's line is the header's, whatever the header said before
            continue
        if d:
            if type_known(*d):
                out[real] = (fn, f"{d[0]} {real}({d[1] or ''});".replace("* ", "*").replace(" *", " *"))
                FROM_DEF.add(real)
            continue
        e = ext.get(real) or ext.get(fn)
        if e and type_known(*e):
            out[real] = (fn, f"{e[0]} {real}({e[1]});".replace("* ", "*"))
            continue
        p, fl, ptr, _ = scans[fn]
        n = max(p, 1 if fl else 0)
        params = []
        for k in range(n):
            t = fl.get(k) if k in fl else ("void *" if k in ptr else "s32")
            params.append(f"{t}{'' if t.endswith('*') else ' '}arg{k}")
        u = used.get(fn, set())
        ret = "void *" if "ptr" in u else "f64" if "f64" in u else "f32" if "f32" in u else "s32" if "int" in u else "void"
        out[real] = (fn, f"{ret}{'' if ret.endswith('*') else ' '}{real}({', '.join(params)});")
    return out


@functools.lru_cache(maxsize=1)
def overlay_names():
    """{overlay index: {our name: name of the reference}} from config/overlays/names.txt."""
    out = {}
    path = ROOT / "config" / "overlays" / "names.txt"
    if path.exists():
        for line in path.read_text().splitlines():
            parts = line.split("#", 1)[0].split()
            if len(parts) == 3:
                out.setdefault(parts[0], {})[parts[1]] = parts[2]
    return out


def write_header(seg: str, protos: dict):
    guard = re.sub(r"\W", "_", header_name(seg)).upper()
    old = {}
    if header_path(seg).exists():   # a line already in the header stays as it is (files verified against it keep holding)
        for l in header_path(seg).read_text().splitlines():
            m = re.match(r"^[^/(]*?(\w+)\(.*?\);", l)
            if m:
                old[m.group(1)] = re.sub(r"\s*/\*.*", "", l)
    protos = {r: (fn, old[r] if r in old and r not in FROM_DEF else p) for r, (fn, p) in protos.items()}
    for real, fn in IMPORTED.items():   # the older files that call them were checked against the line that is there: it stays
        if real in old and real not in protos:
            protos[real] = (fn, old[real])
    ovl_names = overlay_names().get(seg[3:], {}) if seg.startswith("ovl") else {}   # config/overlays/names.txt
    tags = sorted(set(re.findall(r"\b(?:struct|union) \w+(?= ?\*)", "".join(p for _, p in protos.values()))))
    fwd = "".join(f"{t};\n" for t in tags) + ("\n" if tags else "")   # tagged pointers in a prototype: the tag is declared at file scope
    body = fwd + "".join(f"{p}  /* {fn[5:] if fn != real else ovl_names.get(fn, '')} */\n".replace("  /*  */", "") for real, (fn, p) in
                   sorted(protos.items(), key=lambda kv: kv[1][0]))
    head = ("/* Generated by tools/signatures/sig_header.py: the prototypes of every function of this segment. A function with verified C\n"
            "   has the prototype of its definition; the others are read from the assembly (arguments, pointers, floats, result). */\n"
            f"#ifndef {guard}\n#define {guard}\n\n#include \"types.h\"\n\n")
    path = header_path(seg)
    path.parent.mkdir(parents=True, exist_ok=True)
    text = head + body + "\n#endif\n"
    if not path.exists() or path.read_text() != text:   # same text, same file: the object cache keys on the headers
        path.write_text(text)


def use(seg: str, fn: str, real: str, hdr: str, declared: set):
    path = retype.source(seg, fn)
    if not path.exists():
        return "pending"
    old = path.read_text()
    if "generated/mm/" in old:
        return "imported"
    inc = f'#include "{hdr}"'
    if inc in old:   # verified before: the header may have changed since, so check again and go back to the committed file
        if retype.matches(seg, fn, path):
            return "already"
        subprocess.run(["git", "checkout", "-q", "--", str(path)], cwd=ROOT)
        return "already" if retype.matches(seg, fn, path) else "failed: no longer matches the header"
    new = old
    for name in declared:   # the file's own `extern` of a function the header declares
        new = re.sub(r"^(?:extern\s+)?(?:[A-Za-z_]\w*[\s\*]+)+" + re.escape(name) + r"\s*\([^;{}]*\)\s*;[ \t]*\n", "", new, flags=re.M)
    new = re.sub(tidy_perm.TYPEDEF.pattern + r"[ \t]*\n", "", new, flags=re.M)   # types.h, now included, defines these
    lines = new.split("\n")
    last = max((i for i, l in enumerate(lines) if l.startswith("#include")), default=-1)
    lines.insert(last + 1, inc)
    path.write_text("\n".join(lines))
    if retype.matches(seg, fn, path):
        return "converted"
    try:
        want, _ = match.original(seg, fn)
        match.compiled(path, fn, match.file_flags(path), len(want))
        why = "bytes differ"
    except Exception as e:
        m = re.findall(r"Error: [^\n]*?line \d+: ([^\n]*)", str(e))
        why = (m[0] if m else str(e).strip().split("\n")[-1])[:90]
    path.write_text(old)
    return "failed: " + why


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("-")]
    jobs = int(sys.argv[sys.argv.index("-j") + 1]) if "-j" in sys.argv else objcache.JOBS
    segs = [f"ovl{l.split()[0]}" for l in (ROOT / "config/overlays/list.txt").read_text().splitlines() if l.strip()] \
        if args[0] == "overlays" else [args[0]]
    total = {}
    for seg in segs:
        protos = build(seg)
        write_header(seg, protos)
        if "--apply" not in sys.argv:
            print(f"{seg}: {len(protos)} prototypes -> {header_path(seg).relative_to(ROOT)}")
            continue
        declared = set(protos)
        todo = [(seg, fn, real, header_name(seg), declared) for real, (fn, _) in protos.items()]
        with ThreadPoolExecutor(jobs) as ex:
            for state in ex.map(lambda a: use(*a), todo):
                total[state] = total.get(state, 0) + 1
    if total:
        fails = {k: v for k, v in total.items() if k.startswith("failed")}
        print(" ".join(f"{k}={v}" for k, v in sorted(total.items()) if k not in fails) + f" failed={sum(fails.values())}")
        for k, v in sorted(fails.items(), key=lambda kv: -kv[1])[:12]:
            print(f"  {v:4d} {k[8:]}")


if __name__ == "__main__":
    main()
