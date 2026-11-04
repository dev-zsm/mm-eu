#!/usr/bin/env python3
"""Functions of `code` that the reference decompilation compiles to the very bytes of this ROM, written as C files of ours. Run in WSL.
usage: ref_import.py vendor                 copy the headers of the reference clone (build/ref/mm) to include/mm/, with stand-ins for the
                                            generated asset headers (not distributable; every function is checked byte for byte anyway)
       ref_import.py run [--only file.c] [-j N]   compile every reference file of src/code, keep the functions that are byte-identical to
                                            ours and that we do not have in C yet, write them to src/code/ and register their names
How a function becomes a file: the includes, defines and types of the reference file, the other declarations of that file as `extern`
(initialisers dropped), the function itself. A symbol that the reference calls or reads under another name than the one our code
uses gets a `#define` to ours (found by pairing the relocations of the reference object with the ones in our assembly, so the evidence is
the identical code). Nothing is kept unless tools/lib/match.py says MATCH on the file, and the full check still has the last word."""
import collections, re, shutil, struct, subprocess, sys, tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import match  # noqa: E402
import names  # noqa: E402
import objcache  # noqa: E402
import srcpath  # noqa: E402

REF = ROOT / "build" / "ref" / "mm"
new_bases = set()   # symbols at the start of arrays that the imported code reaches with an offset (config/code/bases.txt)
MM = ROOT / "include" / "mm"
INC = ROOT / "include" / "generated" / "mm"   # one header per reference file that gave functions
SEG = "code"
FLAGS_LINE = ("-O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE "
              "-DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc")
REF_FLAGS = ["-c", "-G", "0", "-non_shared", "-Xcpluscomm", "-nostdinc", "-Wab,-r4300_mul", "-w", "-D_MIPS_SZLONG=32", "-DF3DEX_GBI_2",
             "-DF3DEX_GBI_PL", "-DGBI_DOWHILE", "-DMM_VERSION=N64_US", "-D_LANGUAGE_C", "-Iinclude", "-Iinclude/libc", "-Isrc",
             "-Ibuild/n64-us", "-I.", "-Iextracted/n64-us", "-EB", "-O2", "-g3", "-mips2"]


def run(*a, **k):
    return subprocess.run(a, capture_output=True, text=True, **k)


# ---------------------------------------------------------------- vendor
def vendor():
    """include/mm/: the headers of the reference and the stand-ins for the generated asset headers."""
    if not REF.exists():
        REF.parent.mkdir(parents=True, exist_ok=True)
        run("git", "clone", "--depth", "1", "https://github.com/zeldaret/mm", str(REF))
    shutil.rmtree(MM, ignore_errors=True)
    shutil.copytree(REF / "include", MM)
    for h in (REF / "src").rglob("*.h"):   # the headers of the overlays that z64*.h include (the reference adds -Isrc)
        dst = MM / h.relative_to(REF / "src")
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(h, dst)
    for h in (REF / "assets").rglob("*.h"):   # the asset headers that are part of the reference repository itself
        dst = MM / h.relative_to(REF)
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(h, dst)
    stub = REF / "extracted" / "n64-us"   # only the stand-ins written by stub_loop live there
    if stub.exists():
        shutil.copytree(stub, MM, dirs_exist_ok=True)
    commit = run("git", "-C", str(REF), "rev-parse", "HEAD").stdout.strip()
    (MM / "REFERENCE_COMMIT").write_text(commit + "\n")   # the import can be redone exactly
    print(f"{sum(1 for _ in MM.rglob('*') if _.is_file())} files in {MM.relative_to(ROOT)} (reference {commit[:8]})")


# ---------------------------------------------------------------- the reference side
def stub_loop(files):
    """Create the stand-ins the compile errors ask for (empty headers, externs for undeclared identifiers), until nothing is missing."""
    base = REF / "extracted" / "n64-us"
    syms = base / "assets" / "_syms.h"
    (base / "assets").mkdir(parents=True, exist_ok=True)
    syms.touch()
    known = set(re.findall(r"extern u8 (\w+)\[\];", syms.read_text()))
    for _ in range(14):
        errs = []

        def one(f):
            with tempfile.TemporaryDirectory() as d:
                r = run(str(objcache._compiler("71")), *REF_FLAGS, "-o", d + "/x.o", str(f.relative_to(REF)), cwd=REF)
                if r.returncode:
                    errs.append(r.stderr)

        with ThreadPoolExecutor(objcache.JOBS) as ex:
            list(ex.map(one, files))
        new, add = 0, []
        text = "\n".join(errs)
        for m in re.finditer(r"Cannot open file (\S+) for #include", text):
            p = base / m.group(1)
            if not p.exists():
                p.parent.mkdir(parents=True, exist_ok=True)
                p.write_text('#include "assets/_syms.h"\n')
                new += 1
        for m in re.finditer(r"'(\w+)' undefined", text):
            if m.group(1) not in known:
                known.add(m.group(1))
                add.append(m.group(1))
                new += 1
        if add:
            with syms.open("a") as f:
                f.write("".join(f"extern u8 {n}[];\n" for n in add))
        if not new:
            break


def ref_functions(obj):
    """{name: (offset, bytes, [(offset in function, relocation type, symbol)])} of the functions of a reference object."""
    nm = run("mips-linux-gnu-nm", "-S", "--defined-only", str(obj)).stdout
    with tempfile.TemporaryDirectory() as d:
        run("mips-linux-gnu-objcopy", "-O", "binary", "--only-section=.text", str(obj), d + "/t.bin")
        blob = Path(d, "t.bin").read_bytes() if Path(d, "t.bin").exists() else b""
    rel = run("mips-linux-gnu-readelf", "-rW", str(obj)).stdout.split("Relocation section")
    rels = []
    for sec in rel:
        if sec.startswith(" '.rel.text'"):
            rels = [(int(m.group(1), 16), m.group(2), m.group(3)) for m in
                    re.finditer(r"^([0-9a-f]{8})\s+[0-9a-f]+\s+(R_MIPS_\w+)\s+[0-9a-f]+\s+(\S+)", sec, re.M)]
    out = {}
    for m in re.finditer(r"^([0-9a-f]{8}) ([0-9a-f]{8}) [Tt] (\w+)$", nm, re.M):
        off, size, name = int(m.group(1), 16), int(m.group(2), 16), m.group(3)
        out[name] = (off, blob[off:off + size], [(o - off, t, s) for o, t, s in rels if off <= o < off + size])
    return out


# ---------------------------------------------------------------- our side
OURS_SYM = re.compile(r"(?:%(?:hi|lo)\(\s*([A-Za-z_.][\w.]*)|\bjal\s+([A-Za-z_.][\w.]*))")
US = re.compile(r"\b((?:func|D)_[0-9A-Fa-f]{8})\b")
ASM_LINE = re.compile(r"/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s+[0-9A-F]{8}\s*\*/\s+(.*)")


def our_symbols(fn):
    """{offset in function: symbol} for every relocated operand of our assembly of `fn`."""
    text = match.asm_file(SEG).read_text()
    m = re.search(r"^nonmatching " + fn + r", .*?(?=^nonmatching |\Z)", text, re.M | re.S)
    if not m:
        return None
    start = int(fn[-8:], 16)
    out = {}
    for line in m.group(0).split("\n"):
        a = ASM_LINE.match(line.strip())
        if a:
            s = OURS_SYM.search(a.group(2))
            if s:
                out[int(a.group(1), 16) - start] = s.group(1) or s.group(2)
    return out


def s16(v):
    return v - 0x10000 if v & 0x8000 else v


def address_of(sym):
    m = re.fullmatch(r"(?:func|D)_([0-9A-F]{8})", sym)
    return int(m.group(1), 16) if m else None


def pair(fn, relocs, blob):
    """{reference symbol: address of the symbol itself} or None when the two sides disagree. The assembly names the exact address a
    relocation reaches; the object says how far past the symbol that is (the addend in the immediate field), so the symbol is
    the difference: `gSegments[6]` is reached at D_801EFA18 and the array starts at D_801EFA00."""
    ours = our_symbols(fn)
    if ours is None:
        return None
    bases, exact = {}, {}
    for i, (off, typ, sym) in enumerate(relocs):
        if sym.startswith("."):
            continue
        if off not in ours or off + 4 > len(blob):
            return None
        addr = address_of(ours[off])
        if addr is None:
            return None
        word = struct.unpack(">I", blob[off:off + 4])[0]
        if typ == "R_MIPS_26":
            add = (word & 0x3FFFFFF) * 4
        elif typ == "R_MIPS_LO16":
            add = s16(word & 0xFFFF)
        elif typ == "R_MIPS_HI16":
            lo = next((o for o, t, y in relocs[i + 1:] if t == "R_MIPS_LO16" and y == sym), None)
            if lo is None or lo + 4 > len(blob):
                continue
            add = ((word & 0xFFFF) << 16) + s16(struct.unpack(">I", blob[lo:lo + 4])[0] & 0xFFFF)
        else:
            continue
        base = addr - add
        if bases.setdefault(sym, base) != base:
            return None
        if add == 0:
            exact[base] = ours[off]
    return bases, exact


# ---------------------------------------------------------------- the source side
def top_chunks(text):
    """Split a C file into top-level chunks: ('pp', line), ('func', name, text), ('decl', text). Comments are dropped."""
    out, i, n = [], 0, len(text)
    buf, depth, par, first_brace = [], 0, 0, None

    def flush(kind):
        s = "".join(buf).strip()
        buf.clear()
        if s:
            out.append((kind, s))

    while i < n:
        c = text[i]
        if depth == 0 and par == 0 and c == "#" and not "".join(buf).strip():
            j = i
            while True:
                e = text.find("\n", j)
                e = n if e < 0 else e
                if text[j:e].rstrip().endswith("\\") and e < n:
                    j = e + 1
                    continue
                break
            out.append(("pp", text[i:e].strip()))
            i = e + 1
            continue
        if text.startswith("//", i):
            e = text.find("\n", i)
            i = n if e < 0 else e
            continue
        if text.startswith("/*", i):
            e = text.find("*/", i + 2)
            i = n if e < 0 else e + 2
            buf.append(" ")
            continue
        if c in "\"'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            buf.append(text[i:j + 1])
            i = j + 1
            continue
        buf.append(c)
        if c == "(":
            par += 1
        elif c == ")":
            par -= 1
        elif c == "{":
            if depth == 0:
                first_brace = len("".join(buf)) - 1
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                head = "".join(buf)[:first_brace].rstrip()
                if head.endswith(")") and "=" not in head and not re.match(r"\s*(typedef|struct|union|enum)\b", head):
                    flush("func")
        elif c == ";" and depth == 0 and par == 0:
            flush("decl")
        i += 1
    return out


def func_name(chunk):
    head = chunk[:chunk.index("{")]
    m = re.search(r"(\w+)\s*\(", head)
    return m.group(1) if m else None


def as_extern(decl):
    """A top-level declaration of the reference file as an `extern` one: no initialiser, no `static`."""
    s = decl
    if re.match(r"\s*(typedef|struct|union|enum)\b.*\{", s, re.S) and "=" not in s.split("{")[0]:
        return s + ""  # a type definition stays as it is
    if re.match(r"\s*typedef\b", s):
        return s
    eq = None
    d = 0
    for k, ch in enumerate(s):
        if ch in "([{":
            d += 1
        elif ch in ")]}":
            d -= 1
        elif ch == "=" and d == 0:
            eq = k
            break
    if eq is not None:
        s = s[:eq].rstrip()
    s = re.sub(r"\bstatic\b\s*", "", s).strip()
    if "(" in s and eq is None:
        return s  # a prototype
    if not s.startswith("extern"):
        s = "extern " + s
    return s


def build_header(stem, chunks, aliases):
    """The context of one reference file, written once: the aliases first (so that they also rename the declarations of the reference
    headers), then its includes, defines and types, its other declarations as `extern`, and a prototype for each of its functions."""
    guard = "MM_" + re.sub(r"\W", "_", stem).upper() + "_H"
    out = ["/* Generated by tools/search/ref_import.py: what the functions imported from one file of the reference need. */",
           f"#ifndef {guard}", f"#define {guard}", ""]
    out += [f"#define {a} {b}" for a, b in sorted(aliases.items())]
    n_alias = len(out)
    for ch in chunks:
        if ch[0] == "pp":
            if not ch[1].startswith("#pragma"):
                out.append(ch[1])
        elif ch[0] == "func":
            out.append(re.sub(r"\b(static|inline)\b\s*", "", ch[1][:ch[1].index("{")].rstrip()) + ";")
        else:
            out.append(as_extern(ch[1]) + ";")
    out += ["", "#endif", ""]
    # the reference's own address names are prefixed; the aliases point at names of ours, which stay as they are
    return "\n".join(out[:n_alias] + [US.sub(r"ref_\1", line) for line in out[n_alias:]])


def function_file(stem, chunks, real):
    body = next(ch[1] for ch in chunks if ch[0] == "func" and func_name(ch[1]) == real)
    return f'// FLAGS: {FLAGS_LINE}\n#include "generated/mm/{stem}.h"\n\n' + US.sub(r"ref_\1", body) + "\n"


# ---------------------------------------------------------------- the run
def candidates(only=None):
    """{reference file: (chunks, [(our function, reference name)])} for the functions that are byte-identical to ours."""
    NM = names.load(SEG)
    rev = {v: k for k, v in NM.items()}
    have = {p.stem for p in srcpath.files(SEG)}
    sizes = match._sizes(SEG)
    files = sorted((REF / "src" / SEG).glob("*.c"))
    if only:
        files = [f for f in files if f.name == only]
    stub_loop(files)
    vendor()   # after the stand-ins: our compile of the imported files reads include/mm
    out = {}

    def one(f):
        with tempfile.TemporaryDirectory() as d:
            obj = Path(d) / "x.o"
            r = run(str(objcache._compiler("71")), *REF_FLAGS, "-o", str(obj), str(f.relative_to(REF)), cwd=REF)
            if r.returncode:
                return f.name, None
            fns = ref_functions(obj)
        items = []
        for real, (off, blob, relocs) in fns.items():
            fn = rev.get(real)   # only functions that already carry their name: the pairing needs it
            if fn is None or fn not in sizes or fn in have:
                continue
            want, _ = match.original(SEG, fn)
            masks = {o: match.MASKS[t] for o, t, s in relocs if t in match.MASKS}
            if len(want) == len(blob) and match.mask(want, masks) == match.mask(blob, masks):
                items.append((fn, real))
        return f.name, (top_chunks(f.read_text()), items) if items else None

    with ThreadPoolExecutor(objcache.JOBS) as ex:
        for name, got in ex.map(one, files):
            if got:
                out[name] = got
    return out


def import_module(fname, chunks, items, reasons):
    """Two passes over the functions of one reference file. The first compiles each with a header that has no alias: the relocations of
    that object name every symbol the way the source spells it (the ones of the reference file itself too, which the reference object
    only reaches through its sections), and pairing them with our assembly says which symbol of ours each one is. The second writes the
    aliases, shared by the whole file, and checks every function again. Returns how many files were kept."""
    stem = Path(fname).stem
    header = INC / f"{stem}.h"
    header.parent.mkdir(parents=True, exist_ok=True)
    header.write_text(build_header(stem, chunks, {}))
    pairs, kept = {}, []
    for fn, real in items:
        path = srcpath.path(SEG, fn)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(function_file(stem, chunks, real))
        why = None
        try:
            want, _ = match.original(SEG, fn)
            got, _ = match.compiled(path, fn, match.file_flags(path), len(want))
            pr = pair(fn, match.last_relocs(), got)
            if pr is None:
                why = "no pairing with our assembly"
        except Exception as e:
            pr, why = None, "does not compile" if isinstance(e, subprocess.CalledProcessError) else f"tool error: {type(e).__name__}"
        if why:
            reasons[why] += 1
            path.unlink(missing_ok=True)
            continue
        pairs[fn] = pr
        kept.append((fn, path))
    bases, exact = {}, {}
    for fn, path in list(kept):
        b, e = pairs[fn]
        if any(bases.setdefault(sym, base) != base for sym, base in b.items()):
            reasons["a symbol at two addresses"] += 1
            path.unlink(missing_ok=True)
            kept.remove((fn, path))
            continue
        exact.update(e)
    nm = names.load(SEG)
    aliases = {}
    for sym, base in bases.items():
        token = exact.get(base)
        target = nm.get(token, token) if token is not None else f"D_{base:08X}"
        if token is None:
            new_bases.add(target)
        if sym != target:
            aliases[sym] = target
    header.write_text(build_header(stem, chunks, aliases))
    good = 0
    for fn, path in kept:
        if _matches(fn, path):
            good += 1
        else:
            reasons["bytes or call targets differ"] += 1
            if "--keep" not in sys.argv:
                path.unlink(missing_ok=True)
    if not good:
        header.unlink(missing_ok=True)
    return good


def _matches(fn, path):
    try:
        want, _ = match.original(SEG, fn)
        got, masks = match.compiled(path, fn, match.file_flags(path), len(want))
    except Exception:
        return False
    if len(got) > len(want) and not any(got[len(want):]):
        got = got[:len(want)]
    return (len(got) == len(want) and match.mask(want, masks) == match.mask(got, masks)
            and not match.check_targets(want, got, match.last_relocs()))


def save_bases():
    """config/code/bases.txt: `name address` for the symbols above that no label of the assembly defines yet."""
    defined = set()
    for f in (ROOT / "asm" / SEG).rglob("*.s"):
        defined |= set(re.findall(r"^dlabel (\w+)", f.read_text(), re.M))
    und = ROOT / "build" / SEG / "undefined_syms_auto.txt"
    if und.exists():
        defined |= set(re.findall(r"^(\w+) =", und.read_text(), re.M))
    path = ROOT / "config" / SEG / "bases.txt"
    have = set(re.findall(r"^(\w+) ", path.read_text(), re.M)) if path.exists() else set()
    head = "" if path.exists() else ("# Symbols at the start of an array that a function reaches with an offset: the assembly names the address it uses,\n"
                                     "# not the start. `name address`, written by tools/search/ref_import.py and linked like the aliases of the boot segment.\n")
    add = sorted(n for n in new_bases if n not in defined and n not in have)
    if add:
        with path.open("a") as f:
            f.write(head + "".join(f"{n} 0x{n[2:]}\n" for n in add))


def main():
    if sys.argv[1:2] == ["vendor"]:
        return vendor()
    only = sys.argv[sys.argv.index("--only") + 1] if "--only" in sys.argv else None
    cands = candidates(only)
    reasons = collections.Counter()
    total = sum(len(items) for _, items in cands.values())
    with ThreadPoolExecutor(objcache.JOBS) as ex:
        ok = sum(ex.map(lambda kv: import_module(kv[0], kv[1][0], kv[1][1], reasons), cands.items()))
    save_bases()
    print(f"{total} identical candidates in {len(cands)} files, {ok} written and verified, {total - ok} rejected")
    for why, n in reasons.most_common():
        print(f"  {n:4d} {why}")


if __name__ == "__main__":
    main()
