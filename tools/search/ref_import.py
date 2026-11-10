#!/usr/bin/env python3
"""Functions of `code` and of the overlays that the reference decompilation compiles to the very bytes of this ROM, written as C files of ours. Run in WSL.
usage: ref_import.py vendor                 copy the headers of the reference clone (build/ref/mm) to include/mm/, with stand-ins for the
                                            generated asset headers (not distributable; every function is checked byte for byte anyway)
       ref_import.py heal                   link the code segment and delete the untracked files that keep it from linking or compiling
       ref_import.py run [overlays] [--only file.c]   compile every reference file of src/code (or of src/overlays), keep the functions that are byte-identical to
                                            ours and that we do not have in C yet, write them to src/code/ and register their names
How a function becomes a file: the includes, defines and types of the reference file, the other declarations of that file as `extern`
(initialisers dropped), the function itself. A symbol that the reference calls or reads under another name than the one our code
uses gets a `#define` to ours (found by pairing the relocations of the reference object with the ones in our assembly, so the evidence is
the identical code). Nothing is kept unless tools/lib/match.py says MATCH on the file, and the full check still has the last word."""
import bisect, collections, functools, os, re, shutil, struct, subprocess, sys, tempfile, time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import match  # noqa: E402
import names  # noqa: E402
import objcache  # noqa: E402
import srcpath  # noqa: E402

REF = ROOT / "build" / "ref" / "mm"
RUNTIME = {}   # symbols the compiler itself calls (__ull_div ...): no source spells them, so the linker is told where they are
WRITTEN = []   # the files this run kept: dropped again if the segment does not link with them (link_guard)
new_bases = set()   # symbols at the start of arrays that the imported code reaches with an offset (config/code/bases.txt)
MM = ROOT / "include" / "mm"
INC = ROOT / "include" / "generated" / "mm"   # one header per reference file that gave functions
SEG = "code"
FLAGS_LINE = ("-O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE "
              "-DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc")
REF_FLAGS = ["-c", "-G", "0", "-non_shared", "-Xcpluscomm", "-nostdinc", "-Wab,-r4300_mul", "-w", "-D_MIPS_SZLONG=32", "-DF3DEX_GBI_2",
             "-DF3DEX_GBI_PL", "-DGBI_DOWHILE", "-DMM_VERSION=N64_US", "-D_LANGUAGE_C", "-Iinclude", "-Iinclude/libc", "-Isrc",
             "-Ibuild/n64-us", "-I.", "-Iextracted/n64-us", "-EB", "-O2", "-g3", "-mips2"]


_T0 = [time.perf_counter()]


def lap(label):
    """How long the last phase took (printed with --time)."""
    now = time.perf_counter()
    if "--time" in sys.argv:
        print(f"  [{now - _T0[0]:6.1f} s] {label}", flush=True)
    _T0[0] = now


def run(*a, **k):
    return subprocess.run(a, capture_output=True, text=True, **k)


_FP = [None]   # fingerprint of the stand-ins (see stand_state), set by stub_loop before each round


def stand_state():
    """What a failed compile of the reference depends on besides the file: the stand-ins written so far."""
    base = REF / "extracted" / "n64-us"
    files = sorted(p for p in base.rglob("*") if p.is_file()) if base.exists() else []
    return objcache.digest(*(str(p.relative_to(base)).encode() + b"\0" + p.read_bytes() for p in files))[:16]


@functools.lru_cache(maxsize=1)
def ref_commit():
    return run("git", "-C", str(REF), "rev-parse", "HEAD").stdout.strip()


def ref_compile(f):
    """(object, error) of a reference file compiled with the flags of the reference. The object is kept while the file and the version
    of the reference stay the same: a stand-in written later cannot change a file that already compiled, so only the files that failed
    are compiled again when the stand-ins grow, and a second run does not compile anything."""
    key = objcache.digest(ref_commit().encode(), str(f.relative_to(REF)).encode(), f.read_bytes())
    obj = objcache.CACHE / "ref" / f"{key}.o"
    if obj.exists():
        return obj, ""
    obj.parent.mkdir(parents=True, exist_ok=True)
    if _FP[0] is None:
        _FP[0] = stand_state()
    failure = obj.with_name(f"{key}.{_FP[0]}.err")   # a failure holds for the stand-ins it was compiled with
    if failure.exists():
        return None, failure.read_text(errors="replace")
    with tempfile.TemporaryDirectory() as d:
        r = run(str(objcache._compiler("71")), *REF_FLAGS, "-o", d + "/x.o", str(f.relative_to(REF)), cwd=REF)
        if r.returncode:
            failure.write_text(r.stderr)
            return None, r.stderr
        tmp = obj.with_suffix(f".{os.getpid()}.tmp")
        shutil.move(d + "/x.o", tmp)
        os.replace(tmp, obj)   # atomic: threads may compile the same file
    return obj, ""


# ---------------------------------------------------------------- vendor
def copy_new(src, dst):
    """Copy a file unless the same one is already there (the copy of ~1500 small files took a minute on the Windows disk)."""
    if dst.exists() and dst.stat().st_size == src.stat().st_size and dst.read_bytes() == src.read_bytes():
        return
    dst.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(src, dst)


def vendor():
    """include/mm/: the headers of the reference and the stand-ins for the generated asset headers."""
    if not REF.exists():
        REF.parent.mkdir(parents=True, exist_ok=True)
        run("git", "clone", "--depth", "1", "https://github.com/zeldaret/mm", str(REF))
    commit = ref_commit()
    stamp = MM / "REFERENCE_COMMIT"
    # the stamp is written after the copy: with the same version of the reference, include/ src/ and assets/ are already in include/mm
    # (the copy of ~1500 small files took a minute on the Windows disk); the stand-ins grow from run to run, so they are always looked at
    done = stamp.exists() and stamp.read_text().strip() == commit
    # additive: the stand-ins of earlier runs stay
    for base, dst_base in (((REF / "extracted" / "n64-us", MM),) if done else
                           ((REF / "include", MM), (REF / "src", MM), (REF / "assets", MM / "assets"), (REF / "extracted" / "n64-us", MM))):
        for h in base.rglob("*"):   # the last base holds only the stand-ins written by stub_loop
            if h.is_file() and (base != REF / "src" and base != REF / "assets" or h.suffix == ".h"):
                copy_new(h, dst_base / h.relative_to(base))
    stamp.write_text(commit + "\n")   # the import can be redone exactly
    print(f"include/mm: reference {commit[:8]}" + (" (headers already copied)" if done else ""))


# ---------------------------------------------------------------- the reference side
def stub_loop(files):
    """Create the stand-ins the compile errors ask for (empty headers, externs for undeclared identifiers), until nothing is missing."""
    base = REF / "extracted" / "n64-us"
    syms = base / "assets" / "_syms.h"
    (base / "assets").mkdir(parents=True, exist_ok=True)
    syms.touch()
    kept = MM / "assets" / "_syms.h"   # the stand-ins of the repository: a clone that has fewer must not shrink them (files in src/ use them)
    if kept.exists():
        have = syms.read_text().splitlines()
        syms.write_text("\n".join(have + [l for l in kept.read_text().splitlines() if l not in set(have)]) + "\n")
    known =set(re.findall(r"extern u8 (\w+)\[\];", syms.read_text()))
    todo = list(files)
    for _ in range(14):
        _FP[0] = stand_state()
        errs = {}

        def one(f):
            obj, err = ref_compile(f)
            if obj is None:
                errs[f] = err

        with ThreadPoolExecutor(objcache.JOBS) as ex:
            list(ex.map(one, todo))
        made = set()   # what this round created: the files whose error names it are compiled again, the others cannot change
        for err in errs.values():
            for m in re.finditer(r"Cannot open file (\S+) for #include", err):
                p = base / m.group(1)
                if not p.exists():
                    p.parent.mkdir(parents=True, exist_ok=True)
                    p.write_text('#include "assets/_syms.h"\n')
                    made.add(m.group(1))
            add = []
            for m in re.finditer(r"'(\w+)' undefined", err):
                if m.group(1) not in known:
                    known.add(m.group(1))
                    add.append(m.group(1))
                    made.add(m.group(1))
            if add:
                with syms.open("a") as f:
                    f.write("".join(f"extern u8 {n}[];\n" for n in add))
        if not made:
            break
        todo = [f for f, err in errs.items()
                if any(re.search(rf"Cannot open file {re.escape(n)} for #include|'{re.escape(n)}' undefined", err) for n in made)]


def ref_functions(obj):
    """{name: (offset, bytes, [(offset in function, relocation type, symbol)])} of the functions of a reference object."""
    text, _, inside, relocs = match.elf_text(str(obj))
    relocs = sorted(relocs)
    offsets = [r[0] for r in relocs]
    return {name: (off, text[off:off + size], [(o - off, t, sym) for o, t, sym in relocs[bisect.bisect_left(offsets, off):bisect.bisect_left(offsets, off + size)]])
            for name, (off, size) in inside.items() if size}


# ---------------------------------------------------------------- our side
OURS_SYM = re.compile(r"(?:%(?:hi|lo)\(\s*([A-Za-z_.][\w.]*)|\bjal\s+([A-Za-z_.][\w.]*))")
US = re.compile(r"\b((?:func|D)_[0-9A-Fa-f]{8})\b")
ASM_LINE = re.compile(r"/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s+[0-9A-F]{8}\s*\*/\s+(.*)")


@functools.lru_cache(maxsize=4)
def asm_text(seg):
    return match.asm_file(seg).read_text()


@functools.lru_cache(maxsize=None)
def overlay_dir(index):
    return srcpath.overlay_dir(index)   # a glob of src/overlays: 13,000 of them took a minute and a half on the Windows disk


def source_path(seg, fn):
    """Where the C file of one of our functions lives: src/overlays/<index>/ for an overlay, else src/<seg>/<module>/."""
    return overlay_dir(seg[3:]) / f"{fn}.c" if seg.startswith("ovl") else srcpath.path(seg, fn)


def our_symbols(seg, fn):
    """{offset in function: symbol} for every relocated operand of our assembly of `fn`."""
    text = asm_text(seg)
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
    m = re.fullmatch(r"(?:func|D|jtbl)_([0-9A-F]{7,8})", sym)   # splat names a rodata table of code pointers jtbl_
    return int(m.group(1), 16) if m else None


class PairError(Exception):
    """Why a function could not be paired with our assembly."""


def compile_error(path):
    """The first error IDO gives for a file, with the names blanked, to count the causes."""
    with tempfile.TemporaryDirectory() as d:
        r = run(str(objcache._compiler("71")), "-c", *FLAGS_LINE.split(), "-G", "0", "-non_shared", "-Xcpluscomm", "-w",
                "-I" + str(ROOT / "include"), "-o", d + "/x.o", str(path))
    m = re.search(r"Error: [^\n]*?line \d+: ([^\n]*)", r.stderr)
    return re.sub(r"'[^']*'", "'X'", m.group(1))[:80] if m else "?"


def pair(seg, fn, relocs, blob):
    """{reference symbol: address of the symbol itself}, raising PairError when the two sides disagree. The assembly names the exact
    address a relocation reaches; the object says how far past the symbol that is (the addend in the immediate field), so the symbol is
    the difference: `gSegments[6]` is reached at D_801EFA18 and the array starts at D_801EFA00."""
    ours = our_symbols(seg, fn)
    if ours is None:
        raise PairError("function not in our assembly")
    bases, exact = {}, {}
    for i, (off, typ, sym) in enumerate(relocs):
        if sym.startswith("."):
            continue
        if off not in ours or off + 4 > len(blob):
            raise PairError("our assembly has no relocated operand where the object has one")
        addr = address_of(ours[off])
        if addr is None:
            raise PairError("our operand is not a func_/D_/jtbl_ name: " + re.sub("[0-9A-F]{8}", "X", ours[off]))
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
            raise PairError("a symbol at two addresses in one function")
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


def chunks_of(f):
    """The chunks of a reference file, with the `.c` files it includes (`#include "z_en_kanban_gfx.c"`) written in place: its header could not
    include them, they hold definitions and the functions the object has."""
    out = []
    for ch in top_chunks(f.read_text()):
        m = re.fullmatch(r'#include "([^"]+\.c)"', ch[1]) if ch[0] == "pp" else None
        inc = next((p for p in (f.parent / m.group(1), REF / "src" / m.group(1)) if p.is_file()), None) if m else None
        out += chunks_of(inc) if inc else [ch]
    return out


def func_name(chunk):
    head = chunk[:chunk.index("{")]
    m = re.search(r"(\w+)\s*\(", head)
    return m.group(1) if m else None


def initializer_count(init):
    """Number of elements of a `{ a, b, { c, d }, }` initialiser (0 when it is not a brace list). A macro that expands to several elements
    is counted as one: the size is then wrong, and the function that depends on it is rejected by the byte check."""
    init = init.strip().rstrip(";").rstrip()
    if not init.startswith("{") or not init.endswith("}"):
        return 0
    depth, parts, cur, i = 0, 0, False, 0
    while i < len(init):
        c = init[i]
        if c in "\"'":
            j = i + 1
            while j < len(init) and init[j] != c:
                j += 2 if init[j] == "\\" else 1
            i, cur = j, True
        elif c in "({[":
            depth += 1
            cur = cur or depth > 1
        elif c in ")}]":
            depth -= 1
        elif c == "," and depth == 1:
            parts += cur
            cur = False
        elif not c.isspace() and depth >= 1:
            cur = True
        i += 1
    return parts + cur


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
        n = initializer_count(s[eq + 1:])
        s = s[:eq].rstrip()
        if n:   # `T x[]` has no size without its initialiser: sizeof / ARRAY_COUNT need it (a declaration with a size reaches the same symbol)
            s = re.sub(r"\[\s*\]", f"[{n}]", s, count=1)
    s = re.sub(r"\bstatic\b\s*", "", s).strip()
    if "(" in s and eq is None:
        return s  # a prototype
    if not s.startswith("extern"):
        s = "extern " + s
    return s


ALIAS_MARK = "/* names of ours that symbols of the reference stand for */"


def read_aliases(header):
    """The aliases already in a module header (the functions imported earlier depend on them)."""
    if not header.exists():
        return {}
    lines = header.read_text().splitlines()
    if ALIAS_MARK in lines:
        start = lines.index(ALIAS_MARK) + 1
    else:   # the first headers had no marker: the aliases are the defines of names that follow the include guard
        guard = next((i for i, l in enumerate(lines) if l.startswith("#define MM_")), None)
        if guard is None:
            return {}
        start = guard + 1
    out = {}
    for line in lines[start:]:
        if not line.strip() and not out:
            continue
        m = re.fullmatch(r"#define ([A-Za-z_]\w*) ([A-Za-z_]\w*)", line)
        if not m:
            break
        out[m.group(1)] = m.group(2)
    return out


def relkey(f):
    """The reference file as the path below its src/ (it names the file and tells which headers sit next to it)."""
    return f.relative_to(REF / "src").as_posix()


def build_header(stem, chunks, aliases, refdir=""):
    """The context of one reference file, written once: the aliases first (so that they also rename the declarations of the reference
    headers), then its includes, defines and types, its other declarations as `extern`, and a prototype for each of its functions."""
    guard = "MM_" + re.sub(r"\W", "_", stem).upper() + "_H"
    out = ["/* Generated by tools/search/ref_import.py: what the functions imported from one file of the reference need. */",
           f"#ifndef {guard}", f"#define {guard}", ""]
    out += [ALIAS_MARK] + [f"#define {a} {b}" for a, b in sorted(aliases.items())] + [""]
    # an address name that the file uses but only a header of the reference declares (data or functions of `code`): the body spells it with
    # the prefix, so the declaration of the header must too, or the prefixed name is undeclared (an unsized array, a function taken as a
    # value, a call with the wrong argument types). The names are renamed only while the headers are read.
    mine = {name for ch in chunks if ch[0] == "func" for name in [func_name(ch[1])] if name}
    mine |= {x for ch in chunks if ch[0] == "decl" for x in US.findall(as_extern(ch[1]))
             if re.search(rf"\b{x}\b\s*(\[[^\]]*\]\s*)*($|\()", as_extern(ch[1]))}
    outside = sorted({x for ch in chunks if ch[0] != "pp" for x in US.findall(ch[1])} - mine)
    last_include = max((i for i, ch in enumerate(chunks) if ch[0] == "pp" and ch[1].startswith("#include")), default=-1)
    if last_include >= 0:
        out += ["/* names declared by the headers of the reference, prefixed while they are read */"]
        out += [f"#define {x} ref_{x}" for x in outside] + [""]
    tail = []
    for i, ch in enumerate(chunks):
        if ch[0] == "pp":
            if not ch[1].startswith("#pragma"):
                tail.append(US.sub(r"ref_\1", next_to_the_file(ch[1], refdir)))
        elif ch[0] == "func":
            tail.append(US.sub(r"ref_\1", re.sub(r"\b(static|inline)\b\s*", "", ch[1][:ch[1].index("{")].rstrip()) + ";"))
        else:
            tail.append(US.sub(r"ref_\1", as_extern(ch[1]) + ";"))
        if i == last_include:
            tail += [f"#undef {x}" for x in outside]
    return "\n".join(out + tail + ["", "#endif", ""])


def next_to_the_file(line, refdir):
    """`#include "z_en_x.h"` looks next to the reference file first; the header lives elsewhere, so it gets its full path."""
    m = re.match(r'#include "([^"]+)"', line)
    if m and refdir and not (MM / m.group(1)).exists() and (MM / refdir / m.group(1)).exists():
        return f'#include "{refdir}/{m.group(1)}"'
    return line


def ctx_name(stem):
    """Name of the generated header of a reference file: its own name, unless a header of the reference has it (it would include itself)."""
    return stem + "_ctx" if (MM / f"{stem}.h").exists() else stem


def function_file(stem, chunks, real):
    body = next((ch[1] for ch in chunks if ch[0] == "func" and func_name(ch[1]) == real), None)
    if body is None:   # written by a macro, or in an included .c file
        return None
    # IDO drops a static function nobody calls, and this file holds only this one: the symbol must exist to be compared
    body = re.sub(r"^(?:\s*(?:static|inline)\b)+\s*", "", body)
    return f'// FLAGS: {FLAGS_LINE}\n#include "generated/mm/{stem}.h"\n\n' + US.sub(r"ref_\1", body) + "\n"


# ---------------------------------------------------------------- the run
NEW_NAMES = {}   # our function -> the name it takes from the reference, for the ones found by their bytes (written to names.txt when kept)
MIN_BYTES = 0x14   # shorter functions are the same few instructions everywhere: their bytes alone prove nothing


def code_candidates(only=None):
    """{reference file: (chunks, [(our function, reference name)])} for the functions that are byte-identical to ours: the ones that
    already carry the name of the reference, then the ones without a name whose bytes match one function of the reference and only
    that one (and that function matches only this one of ours)."""
    NM = names.load(SEG)
    rev = {v: k for k, v in NM.items()}
    have = {p.stem for p in srcpath.files(SEG)}
    sizes = match._sizes(SEG)
    files = sorted((REF / "src" / SEG).glob("*.c"))
    if only:
        files = [f for f in files if f.name == only]
    stub_loop(files)
    vendor()   # after the stand-ins: our compile of the imported files reads include/mm

    def scan(f):
        obj, _ = ref_compile(f)
        return (f, ref_functions(obj)) if obj else (f, None)

    with ThreadPoolExecutor(objcache.JOBS) as ex:
        scans = [s for s in ex.map(scan, files) if s[1]]
    items = collections.defaultdict(list)
    ours_free = collections.defaultdict(list)   # size -> our functions that have no C and no name yet
    for fn, size in sizes.items():
        if fn not in have and fn not in NM and size >= MIN_BYTES:
            ours_free[size].append(fn)
    claims = collections.defaultdict(list)
    seen = collections.Counter(real for _, fns in scans for real in fns)
    for f, fns in scans:
        for real, (off, blob, relocs) in fns.items():
            masks = {o: match.MASKS[t] for o, t, s in relocs if t in match.MASKS}
            fn = rev.get(real)
            if fn is not None:
                if fn in sizes and fn not in have:
                    want, _ = match.original(SEG, fn)
                    if len(want) == len(blob) and match.mask(want, masks) == match.mask(blob, masks):
                        items[relkey(f)].append((SEG, fn, real))
            elif seen[real] == 1 and not US.fullmatch(real) and len(blob) >= MIN_BYTES:
                hits = [g for g in ours_free[len(blob)] if match.mask(match.original(SEG, g)[0], masks) == match.mask(blob, masks)]
                if len(hits) == 1:
                    claims[hits[0]].append((relkey(f), real))
    for fn, found in claims.items():
        if len(found) == 1 and found[0][1] not in rev:
            fname, real = found[0]
            NEW_NAMES[fn] = real
            match.NAMES[fn] = real   # the files define the real name; the checks look it up here
            items[fname].append((SEG, fn, real))
    return {relkey(f): (chunks_of(f), items[relkey(f)]) for f, _ in scans if items.get(relkey(f))}


def opcodes(code):
    """The opcode of every instruction: a relocation changes the operands only, so two functions with the same bytes agree on this."""
    return bytes(w >> 26 for w in struct.unpack(f">{len(code) // 4}I", code))


def overlay_candidates(only=None, names_mode=False):
    """{reference file: (chunks, [(overlay segment, our function, reference name)])} for the overlay functions that are byte-identical
    to ours. The reference file is matched to one of our overlays by vote: every function of the file that has the same bytes as functions
    of ours votes for the overlays they are in, and the file belongs to the overlay with most votes. Inside that overlay a function counts
    only if its bytes match one function of ours and nothing else claims it."""
    files = sorted(f for f in (REF / "src" / "overlays").rglob("*.c") if not f.name.endswith(".inc.c"))
    if only:
        files = [f for f in files if f.name == only]
    lap("start")
    stub_loop(files)
    lap("stand-ins")
    vendor()
    lap("vendor")

    def scan(f):
        obj, _ = ref_compile(f)
        return (f, ref_functions(obj)) if obj else (f, None)

    with ThreadPoolExecutor(objcache.JOBS) as ex:
        scans = [s for s in ex.map(scan, files) if s[1]]
    if "--why" in sys.argv:
        print(f"  why {len(files) - len(scans)} of {len(files)} reference files without object: " + " ".join(sorted(f.name for f in files if f not in {s[0] for s in scans}))[:3000])
    lap("reference objects read")
    free = collections.defaultdict(list)   # (size, opcodes) -> [(overlay segment, function, its bytes)] without verified C
    for line in (ROOT / "config" / "overlays" / "list.txt").read_text().splitlines():
        if not line.strip():
            continue
        idx = line.split()[0]
        seg = f"ovl{idx}"
        for fn, size in match._sizes(seg).items():
            if size >= 8 and (names_mode or not source_path(seg, fn).exists()):   # the names are wanted for every function
                code = match.original(seg, fn)[0]
                free[(size, opcodes(code))].append((seg, fn, code))
    lap("our functions indexed")
    items = collections.defaultdict(list)
    claims = collections.defaultdict(list)
    chosen = []   # (reference file, overlay it was matched to, votes)
    for f, fns in scans:
        hits, votes = {}, collections.Counter()
        for real, (off, blob, relocs) in fns.items():
            masks = {o: match.MASKS[t] for o, t, s in relocs if t in match.MASKS}
            key = match.mask(blob, masks)
            found = [(seg, fn) for seg, fn, code in free[(len(blob), opcodes(blob))] if match.mask(code, masks) == key]
            hits[real] = found
            if 1 <= len(found) <= 4:
                for seg in {seg for seg, _ in found}:
                    votes[seg] += 1
        ranked = votes.most_common(2)
        if "--why" in sys.argv:
            print(f"  why {relkey(f)}: {len(fns)} functions, {sum(1 for v in hits.values() if v)} with a twin, votes {votes.most_common(3)}")
        if not ranked or (len(ranked) > 1 and ranked[0][1] == ranked[1][1]):
            continue   # no overlay, or two overlays equally likely: no guess
        best = ranked[0][0]
        chosen.append((f, best, ranked[0][1]))
        for real, found in hits.items():
            inside = [x for x in found if x[0] == best]
            if len(inside) == 1:
                claims[inside[0]].append((relkey(f), real))
    if names_mode:
        return write_overlay_names(claims, chosen, scans)
    for (seg, fn), found in claims.items():
        if len(found) == 1:
            fname, real = found[0]
            items[fname].append((seg, fn, real))
    return {relkey(f): (chunks_of(f), items[relkey(f)]) for f, _ in scans if items.get(relkey(f))}


def embed(short, long):
    """The positions of `long` where the items of `short` appear in order, when there is exactly one way to place them, else None."""
    n, m = len(short), len(long)
    ways = [[0] * (m + 1) for _ in range(n + 1)]   # embeddings of short[i:] in long[j:], counted up to 2
    ways[n] = [1] * (m + 1)
    for i in range(n - 1, -1, -1):
        for j in range(m - 1, -1, -1):
            ways[i][j] = min(2, ways[i][j + 1] + (ways[i + 1][j + 1] if short[i] == long[j] else 0))
    if ways[0][0] != 1:
        return None
    pos, j = [], 0
    for i in range(n):
        while not (short[i] == long[j] and ways[i + 1][j + 1]):
            j += 1
        pos.append(j)
        j += 1
    return pos


NAME_RULES = ("gap", "edge", "partial", "embed", "single")


def aligned_names(claims, chosen, scans, hide=frozenset(), rules=NAME_RULES):
    """{(overlay segment, our function): (name, evidence)} for functions that have no identical bytes in the reference but whose place
    proves the name: the functions of a file are in the same order in the ROM and in the source, and the anchors are the functions with
    identical bytes. Between two anchors of one file (`gap`), or before the first and after the last one (`edge`), when both sides have the
    same number of functions with the same sizes; `partial` when the numbers are equal and only some sizes agree (the others stay
    unnamed); `embed` when the numbers differ but the shorter side has exactly one way to sit in the longer one with the same size and
    instruction opcodes; `single` for the one function left of its size and opcodes on both sides. `hide` anchors are ignored (to test)."""
    out = {}
    fns_of = {f: fns for f, fns in scans}
    for f, seg, votes in chosen:
        if votes < 2:
            continue
        ref = sorted(fns_of[f].items(), key=lambda kv: kv[1][0])   # the functions of the file in source order
        ref_index = {real: i for i, (real, _) in enumerate(ref)}
        ref_key = [(len(v[1]), opcodes(v[1])) for _, v in ref]
        sizes = match._sizes(seg)
        ours = sorted(sizes, key=lambda n: int(n[-8:], 16))
        our_index = {fn: i for i, fn in enumerate(ours)}
        our_key = [(sizes[fn], opcodes(match.original(seg, fn)[0])) for fn in ours]
        anchors = sorted((our_index[fn], ref_index[found[0][1]]) for (s, fn), found in claims.items()
                         if s == seg and len(found) == 1 and found[0][0] == relkey(f) and found[0][1] in ref_index and fn in our_index
                         and (s, fn) not in hide)
        if not anchors:
            continue
        done_o, done_r = {o for o, _ in anchors}, {r for _, r in anchors}
        found = {}   # our index -> (reference index, rule)

        def put(a, b, rule):
            if rules and rule in rules:
                found[a] = (b, rule)
                done_o.add(a)
                done_r.add(b)

        cuts = [(-1, -1)] + anchors + [(len(ours), len(ref))]
        for (o1, r1), (o2, r2) in zip(cuts, cuts[1:]):
            if r2 <= r1 or o2 <= o1:
                continue   # the two orders disagree here
            go, gr = list(range(o1 + 1, o2)), list(range(r1 + 1, r2))
            if not go or not gr:
                continue
            edge = o1 < 0 or o2 == len(ours)
            if len(go) == len(gr):
                same = [(a, b) for a, b in zip(go, gr) if our_key[a][0] == ref_key[b][0]]
                if len(same) == len(go):
                    for a, b in same:
                        put(a, b, "edge" if edge else "gap")
                else:
                    for a, b in same:
                        put(a, b, "partial")
            else:
                short, long_ = (go, gr) if len(go) < len(gr) else (gr, go)
                keys = (our_key, ref_key) if short is go else (ref_key, our_key)
                pos = embed([keys[0][i] for i in short], [keys[1][i] for i in long_])
                if pos is not None:
                    for i, p in zip(short, pos):
                        a, b = (i, long_[p]) if short is go else (long_[p], i)
                        put(a, b, "embed")
        left_o, left_r = collections.defaultdict(list), collections.defaultdict(list)
        for i, k in enumerate(our_key):
            if i not in done_o:
                left_o[k].append(i)
        for i, k in enumerate(ref_key):
            if i not in done_r:
                left_r[k].append(i)
        for k, los in left_o.items():
            if len(los) == 1 and len(left_r.get(k, ())) == 1:
                put(los[0], left_r[k][0], "single")
        why = {"gap": "same rank and size between two functions with identical bytes",
               "edge": "same rank and size after the last (or before the first) function with identical bytes",
               "partial": "same rank and size between two functions with identical bytes (other functions of the gap differ in size)",
               "embed": "only place with the same size and opcodes between two functions with identical bytes",
               "single": "only function of its size and opcodes left on both sides"}
        for a, (b, rule) in found.items():
            out[(seg, ours[a])] = (ref[b][0], why[rule], rule)
    return out


def validate_names(claims, chosen, scans):
    """How many of the names that each rule gives are right: a quarter of the anchors (functions with identical bytes, so the right name
    is known) is hidden, the rules run, and the names they give to the hidden ones are compared with the truth."""
    import random
    rnd = random.Random(1)
    truth = {(seg, fn): found[0][1] for (seg, fn), found in claims.items() if len(found) == 1}
    hide = frozenset(k for k in sorted(truth) if rnd.random() < 0.25)
    stats = collections.defaultdict(collections.Counter)
    for rule in NAME_RULES:
        for key, (real, _, r) in aligned_names(claims, chosen, scans, hide, (rule,)).items():
            if key in hide:
                stats[rule]["right" if truth[key] == real else "wrong"] += 1
            else:
                stats[rule]["on others"] += 1
    for rule in NAME_RULES:
        print(f"  {rule:8s} {dict(stats[rule])}")


def write_overlay_names(claims, chosen, scans):
    """config/overlays/names.txt: `<overlay index> <our name> <name of the reference>   # evidence` for every function of the overlays whose
    bytes are those of exactly one function of the reference, found in the overlay that the vote of its file chose. The file is written
    whole each time. A name that two functions of one overlay would take is dropped (the same static name in two files of the reference)."""
    taken = collections.Counter((seg, found[0][1]) for (seg, fn), found in claims.items() if len(found) == 1)
    rows = []
    for (seg, fn), found in sorted(claims.items()):
        if len(found) != 1:
            continue
        real = found[0][1]
        if taken[(seg, real)] != 1 or US.fullmatch(real) or real.startswith("D_"):
            continue   # ambiguous, or still unnamed in the reference
        rows.append((seg, fn, real, "bytes identical to the reference function of that name, unique match in its overlay"))
    known = {(seg, fn) for seg, fn, _, _ in rows}
    taken_names = collections.Counter((seg, real) for seg, _, real, _ in rows)
    if "--validate" in sys.argv:
        validate_names(claims, chosen, scans)
    aligned = aligned_names(claims, chosen, scans)
    print(f"{len(rows)} names by identical bytes, aligned: " + str(dict(collections.Counter(r for _, _, r in aligned.values()))))
    for (seg, fn), (real, why, _) in sorted(aligned.items()):
        if (seg, fn) not in known and not US.fullmatch(real) and not real.startswith("D_") and taken_names[(seg, real)] == 0:
            rows.append((seg, fn, real, why))
            taken_names[(seg, real)] += 1
    rows.sort()
    rows = [f"{seg[3:]} {fn} {real}   # ref: {why}\n" for seg, fn, real, why in rows]
    head = ("# Names of the functions of the overlays, taken from the reference when their bytes are identical to exactly one of its functions\n"
            "# (tools/search/ref_import.py names). `<overlay index> <our name> <name>`. Not applied to the sources yet.\n")
    (ROOT / "config" / "overlays" / "names.txt").write_text(head + "".join(rows))
    print(f"{len(rows)} names written to config/overlays/names.txt")
    # the name of an overlay is the folder of its files in the reference (ovl_En_Test -> En_Test); with several candidates the best voted wins
    best = {}
    for f, seg, votes in chosen:
        folder = f.parent.name
        if folder.startswith("ovl_") and votes >= 2 and votes > best.get(seg, ("", 0))[1]:
            best[seg] = (folder[4:], votes)
    owners = collections.Counter(name for name, _ in best.values())
    lines = [f"{seg[3:]} {name}   # ref: {votes} functions of its files match this overlay\n"
             for seg, (name, votes) in sorted(best.items()) if owners[name] == 1]
    head = ("# Name of each overlay (the actor, the game state, the menu), from the folder of the reference whose functions match it\n"
            "# (tools/search/ref_import.py names). `<overlay index> <name>`. An overlay two folders claim has no name.\n")
    (ROOT / "config" / "overlays" / "actors.txt").write_text(head + "".join(lines))
    print(f"{len(lines)} overlays named in config/overlays/actors.txt")
    return {}


def save_names():
    """Register the names found by the bytes, as config/code/names.txt does for the others: all of them, kept or not, since the
    files that were imported call these functions by their new name even when the function itself stays assembly."""
    kept = sorted(NEW_NAMES.items())
    if kept:
        with (ROOT / "config" / SEG / "names.txt").open("a") as f:
            f.write("".join(f"{fn} {real}   # ref: bytes identical to the reference function of that name, unique match\n" for fn, real in kept))
    return len(kept)


def import_module(fname, chunks, items, reasons):
    """Two passes over the functions of one reference file. The first compiles each with a header that has no alias: the relocations of
    that object name every symbol the way the source spells it (the ones of the reference file itself too, which the reference object
    only reaches through its sections), and pairing them with our assembly says which symbol of ours each one is. The second writes the
    aliases, shared by the whole file, and checks every function again. Returns how many files were kept."""
    stem = Path(fname).stem
    refdir = Path(fname).parent.as_posix()
    hname = ctx_name(stem)
    header = INC / f"{hname}.h"
    header.parent.mkdir(parents=True, exist_ok=True)
    existed = header.exists()   # an earlier run wrote it: functions already in the repository include it
    known = read_aliases(header)   # kept: the functions of this file imported by an earlier run use them
    overlay = items[0][0] != SEG
    if overlay:   # a function that an earlier run imported under this name has the alias: a second twin of it would take it over
        keep = [it for it in items if known.get(US.sub(r"ref_\1", it[2]), names.load(it[0]).get(it[1], it[1])) == names.load(it[0]).get(it[1], it[1])]
        reasons["name taken by an earlier import"] += len(items) - len(keep)
        items = keep
        if not items:
            return 0
    # an overlay function has no name of ours: the reference's name is an alias of its address name, so that the file defines that
    selfalias = {US.sub(r"ref_\1", real): names.load(seg).get(fn, fn) for seg, fn, real in items} if overlay else {}   # the body spells func_80862B70 as ref_func_80862B70
    header.write_text(build_header(stem, chunks, {**known, **selfalias}, refdir))
    pairs, kept = {}, []
    for seg, fn, real in items:
        path = source_path(seg, fn)
        path.parent.mkdir(parents=True, exist_ok=True)
        text = function_file(hname, chunks, real)
        if text is None:
            reasons["the function is not written in the file (macro or include)"] += 1
            continue
        path.write_text(text)
        why = None
        try:
            want, _ = match.original(seg, fn)
            got, _ = match.compiled(path, fn, match.file_flags(path), len(want))
            pr = pair(seg, fn, match.last_relocs(), got)
        except PairError as e:
            pr, why = None, f"no pairing: {e}"
        except subprocess.CalledProcessError:
            pr, why = None, "does not compile: " + compile_error(path)
        except Exception as e:
            pr, why = None, f"tool error: {type(e).__name__}: {str(e)[:60]}"
            if "--trace" in sys.argv:
                import traceback
                traceback.print_exc(limit=-4)
        if why:
            reasons[why] += 1
            if "--keep" not in sys.argv:
                path.unlink(missing_ok=True)
            continue
        pairs[fn] = pr
        kept.append((seg, fn, path))
    bases, exact = {}, {}
    for seg, fn, path in list(kept):
        b, e = pairs[fn]
        if any(bases.setdefault(sym, base) != base for sym, base in b.items()):
            reasons["a symbol at two addresses"] += 1
            path.unlink(missing_ok=True)
            kept.remove((seg, fn, path))
            continue
        exact.update(e)
    nm = {} if overlay else {**names.load(SEG), **NEW_NAMES}   # the overlays call the code by its address names
    registered = set(nm.values())
    aliases = {}
    text_all = build_header(stem, chunks, known, refdir) + "".join(path.read_text() for _, _, path in kept)
    for sym, base in bases.items():
        if not re.search(r"\b" + re.escape(sym) + r"\b", text_all):   # not in any source: the compiler put it there
            if not overlay:
                RUNTIME[sym] = base
            continue
        if address_of(sym) is not None or sym in known.values():   # already a name of ours (an alias of an earlier run was applied)
            continue
        token = exact.get(base)
        target = nm.get(token, token) if token is not None else f"D_{base:08X}"
        if token is None and not overlay:
            new_bases.add(target)
        if sym != target:
            if sym in registered:   # the reference's name is the name of one of ours: an alias would break everything that calls it
                reasons["a registered name used at another address"] += 1
            else:
                aliases[sym] = target
    for sym, target in list(aliases.items()):
        if known.get(sym, target) != target:   # an earlier run said otherwise: the older files win
            reasons["alias differs from an earlier run"] += 1
            del aliases[sym]
    header.write_text(build_header(stem, chunks, {**known, **aliases, **selfalias}, refdir))
    good = 0
    for seg, fn, path in kept:
        if _matches(seg, fn, path):
            good += 1
            WRITTEN.append(path)
        else:
            reasons["bytes or call targets differ"] += 1
            if "--keep" not in sys.argv:
                path.unlink(missing_ok=True)
    if not good and not existed and "--keep" not in sys.argv:
        header.unlink(missing_ok=True)
    return good


def _matches(seg, fn, path):
    try:
        want, _ = match.original(seg, fn)
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
    runtime = sorted((n, a) for n, a in RUNTIME.items() if n not in defined and n not in have)
    if add or runtime:
        with path.open("a") as f:
            f.write(head + "".join(f"{n} 0x{n[2:]}\n" for n in add) + "".join(f"{n} 0x{a:08X}\n" for n, a in runtime))


UNDEF = re.compile(r"/(\w+)\.o: in function `[^']*':\n(?:[^\n]*\n)*?[^\n]*undefined reference to `([^']+)'")
OBJ_ERR = re.compile(r"AssertionError: (\w+)\.o: non-zero bytes beyond")
CC_ERR = re.compile(r"Error: (\S+?\.c),? line \d+")


def untracked(path):
    """True if git does not know the file: only what an import wrote may be dropped, never a function of the repository."""
    return run("git", "ls-files", "--error-unmatch", str(path), cwd=ROOT).returncode == 1   # any other status (no git here): not known, so kept


def undefined_files(stderr):
    """{source file: symbol} for the objects of a failed link that have an undefined reference and are untracked files."""
    bad = {}
    for m in UNDEF.finditer(stderr):
        path = source_path(SEG, m.group(1))
        if path.exists() and untracked(path):
            bad.setdefault(path, m.group(2))
    for m in OBJ_ERR.finditer(stderr):   # or an object that does not fit its place (a function that the layout splits in several)
        path = source_path(SEG, m.group(1))
        if path.exists() and untracked(path):
            bad.setdefault(path, "an object larger than its place")
    for m in CC_ERR.finditer(stderr):   # or a file that no longer compiles: its header lost the aliases when a round was thrown away
        path = ROOT / m.group(1)
        if path.exists() and untracked(path):
            bad.setdefault(path, "a compile error")
    return bad


def link_guard():
    """An import must never poison the build: link the code segment (tools/lib/build_seg.py) and drop the untracked files whose object has
    an undefined reference (a data symbol of the reference that has no name or address on our side). It also heals files left by an
    earlier round that was thrown away without them. If the link fails for another reason, everything this run wrote goes."""
    orig = ROOT / "extracted" / "0049_00C8A000.bin"
    for _ in range(20):
        r = run(sys.executable, str(ROOT / "tools" / "lib" / "build_seg.py"), SEG, str(orig), cwd=ROOT)
        if r.returncode == 0:
            return
        bad = undefined_files(r.stdout + r.stderr)   # the compiler errors come on stdout (objcache), the linker's on stderr
        for path, sym in bad.items():
            print(f"link: {path.name} dropped, undefined reference to {sym}")
            path.unlink()
        if not bad:
            break
    for path in WRITTEN:
        if path.exists() and untracked(path):
            path.unlink()
    sys.exit("the code segment does not link after the import, the files of this run were dropped\n" + (r.stdout + r.stderr)[-1500:])


def main():
    if sys.argv[1:2] == ["vendor"]:
        return vendor()
    if sys.argv[1:2] == ["heal"]:   # start of a round: drop the untracked files that keep the code segment from linking
        return link_guard()
    only = sys.argv[sys.argv.index("--only") + 1] if "--only" in sys.argv else None
    if sys.argv[1:2] == ["run"] and sys.argv[2:3] == ["names"]:
        overlay_candidates(only, names_mode=True)
        return
    cands = overlay_candidates(only) if sys.argv[2:3] == ["overlays"] else code_candidates(only)
    lap("candidates found")
    reasons = collections.Counter()
    total = sum(len(items) for _, items in cands.values())
    with ThreadPoolExecutor(objcache.JOBS) as ex:
        ok = sum(ex.map(lambda kv: import_module(kv[0], kv[1][0], kv[1][1], reasons), cands.items()))
    lap("functions imported")
    if sys.argv[2:3] != ["overlays"]:
        save_bases()
        link_guard()
        print(f"{save_names()} functions named from the reference by their bytes")
    print(f"{total} identical candidates in {len(cands)} files, {ok} written and verified, {total - ok} rejected")
    for why, n in reasons.most_common():
        print(f"  {n:4d} {why}")


if __name__ == "__main__":
    main()
