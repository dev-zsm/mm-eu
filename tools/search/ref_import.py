#!/usr/bin/env python3
"""Functions of `code` and of the overlays that the reference decompilation compiles to the very bytes of this ROM, written as C files of ours. Run in WSL.
usage: ref_import.py vendor                 copy the headers of the reference clone (build/ref/mm) to include/mm/, with stand-ins for the
                                            generated asset headers (not distributable; every function is checked byte for byte anyway)
       ref_import.py run [overlays] [--only file.c]   compile every reference file of src/code (or of src/overlays), keep the functions that are byte-identical to
                                            ours and that we do not have in C yet, write them to src/code/ and register their names
How a function becomes a file: the includes, defines and types of the reference file, the other declarations of that file as `extern`
(initialisers dropped), the function itself. A symbol that the reference calls or reads under another name than the one our code
uses gets a `#define` to ours (found by pairing the relocations of the reference object with the ones in our assembly, so the evidence is
the identical code). Nothing is kept unless tools/lib/match.py says MATCH on the file, and the full check still has the last word."""
import collections, functools, re, shutil, struct, subprocess, sys, tempfile
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
    shutil.copytree(REF / "include", MM, dirs_exist_ok=True)   # additive: the stand-ins of earlier runs stay
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
    todo = list(files)
    for _ in range(14):
        errs, failed = [], []

        def one(f):
            with tempfile.TemporaryDirectory() as d:
                r = run(str(objcache._compiler("71")), *REF_FLAGS, "-o", d + "/x.o", str(f.relative_to(REF)), cwd=REF)
                if r.returncode:
                    errs.append(r.stderr)
                    failed.append(f)

        with ThreadPoolExecutor(objcache.JOBS) as ex:
            list(ex.map(one, todo))
        todo = failed   # a stand-in only helps the files that failed
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


@functools.lru_cache(maxsize=4)
def asm_text(seg):
    return match.asm_file(seg).read_text()


def source_path(seg, fn):
    """Where the C file of one of our functions lives: src/overlays/<index>/ for an overlay, else src/<seg>/<module>/."""
    return ROOT / "src" / "overlays" / seg[3:] / f"{fn}.c" if seg.startswith("ovl") else srcpath.path(seg, fn)


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
    m = re.fullmatch(r"(?:func|D)_([0-9A-F]{8})", sym)
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
            raise PairError("our operand is not a func_/D_ name (jump table, label)")
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
    n_alias = len(out)
    for ch in chunks:
        if ch[0] == "pp":
            if not ch[1].startswith("#pragma"):
                out.append(next_to_the_file(ch[1], refdir))
        elif ch[0] == "func":
            out.append(re.sub(r"\b(static|inline)\b\s*", "", ch[1][:ch[1].index("{")].rstrip()) + ";")
        else:
            out.append(as_extern(ch[1]) + ";")
    out += ["", "#endif", ""]
    # the reference's own address names are prefixed; the aliases point at names of ours, which stay as they are
    return "\n".join(out[:n_alias] + [US.sub(r"ref_\1", line) for line in out[n_alias:]])


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
        with tempfile.TemporaryDirectory() as d:
            obj = Path(d) / "x.o"
            r = run(str(objcache._compiler("71")), *REF_FLAGS, "-o", str(obj), str(f.relative_to(REF)), cwd=REF)
            return (f, ref_functions(obj)) if r.returncode == 0 else (f, None)

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
    return {relkey(f): (top_chunks(f.read_text()), items[relkey(f)]) for f, _ in scans if items.get(relkey(f))}


def overlay_candidates(only=None):
    """{reference file: (chunks, [(overlay segment, our function, reference name)])} for the overlay functions that are byte-identical
    to ours. The reference file is matched to one of our overlays by vote: every function of the file that has the same bytes as functions
    of ours votes for the overlays they are in, and the file belongs to the overlay with most votes. Inside that overlay a function counts
    only if its bytes match one function of ours and nothing else claims it."""
    files = sorted(f for f in (REF / "src" / "overlays").rglob("*.c") if not f.name.endswith(".inc.c"))
    if only:
        files = [f for f in files if f.name == only]
    stub_loop(files)
    vendor()

    def scan(f):
        with tempfile.TemporaryDirectory() as d:
            obj = Path(d) / "x.o"
            r = run(str(objcache._compiler("71")), *REF_FLAGS, "-o", str(obj), str(f.relative_to(REF)), cwd=REF)
            return (f, ref_functions(obj)) if r.returncode == 0 else (f, None)

    with ThreadPoolExecutor(objcache.JOBS) as ex:
        scans = [s for s in ex.map(scan, files) if s[1]]
    free = collections.defaultdict(list)   # size -> [(overlay segment, function)] without verified C
    for line in (ROOT / "config" / "overlays" / "list.txt").read_text().splitlines():
        if not line.strip():
            continue
        idx = line.split()[0]
        seg = f"ovl{idx}"
        for fn, size in match._sizes(seg).items():
            if size >= 8 and not source_path(seg, fn).exists():
                free[size].append((seg, fn))
    items = collections.defaultdict(list)
    claims = collections.defaultdict(list)
    for f, fns in scans:
        hits, votes = {}, collections.Counter()
        for real, (off, blob, relocs) in fns.items():
            masks = {o: match.MASKS[t] for o, t, s in relocs if t in match.MASKS}
            key = match.mask(blob, masks)
            found = [(seg, fn) for seg, fn in free[len(blob)] if match.mask(match.original(seg, fn)[0], masks) == key]
            hits[real] = found
            if 1 <= len(found) <= 4:
                for seg in {seg for seg, _ in found}:
                    votes[seg] += 1
        ranked = votes.most_common(2)
        if not ranked or (len(ranked) > 1 and ranked[0][1] == ranked[1][1]):
            continue   # no overlay, or two overlays equally likely: no guess
        best = ranked[0][0]
        for real, found in hits.items():
            inside = [x for x in found if x[0] == best]
            if len(inside) == 1:
                claims[inside[0]].append((relkey(f), real))
    for (seg, fn), found in claims.items():
        if len(found) == 1:
            fname, real = found[0]
            items[fname].append((seg, fn, real))
    return {relkey(f): (top_chunks(f.read_text()), items[relkey(f)]) for f, _ in scans if items.get(relkey(f))}


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
    # an overlay function has no name of ours: the reference's name is an alias of its address name, so that the file defines that
    selfalias = {real: fn for seg, fn, real in items} if overlay else {}
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


def main():
    if sys.argv[1:2] == ["vendor"]:
        return vendor()
    only = sys.argv[sys.argv.index("--only") + 1] if "--only" in sys.argv else None
    cands = overlay_candidates(only) if sys.argv[2:3] == ["overlays"] else code_candidates(only)
    reasons = collections.Counter()
    total = sum(len(items) for _, items in cands.values())
    with ThreadPoolExecutor(objcache.JOBS) as ex:
        ok = sum(ex.map(lambda kv: import_module(kv[0], kv[1][0], kv[1][1], reasons), cands.items()))
    if sys.argv[2:3] != ["overlays"]:
        save_bases()
        print(f"{save_names()} functions named from the reference by their bytes")
    print(f"{total} identical candidates in {len(cands)} files, {ok} written and verified, {total - ok} rejected")
    for why, n in reasons.most_common():
        print(f"  {n:4d} {why}")


if __name__ == "__main__":
    main()
