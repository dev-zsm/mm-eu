#!/usr/bin/env python3
"""Real prototypes for the functions of `boot` and `code` whose prototype is only guessed from the assembly (parameters arg0, arg1...),
taken from the headers of the reference decompilation (include/mm, see ref_import.py vendor) by the name the function has in
config/<seg>/names.txt. Run in WSL.
usage: ref_sigs.py <boot|code> [--dry] [-j N]
What it does
  1. reads the prototypes of include/mm/**/*.h and resolves their types: scalars and typedefs of scalars/enums are the integer
     type they are, a pointer to a structure is `struct Tag *` (a tag needs no definition and cannot clash with the typedefs the
     verified files write for themselves); a prototype with a structure by value, a function pointer or a type it cannot resolve is left alone
  2. keeps a reference prototype only if the assembly agrees with it: at least as many parameters as the code reads, a float where the
     code reads $f12/$f14 first, no scalar where the code uses the register as the base of a load or store
  3. writes config/<seg>/sigs.txt (`name prototype`), which sig_header.py uses for the functions that have no C yet, and retypes the
     functions that do (tools/signatures/retype.py: a definition is changed only if it still compiles to the ROM's bytes)
  4. rebuilds the header from the definitions that came out.
Afterwards: sig_header.py <seg> --apply."""
import re, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import objcache  # noqa: E402
import retype  # noqa: E402
import sig_header  # noqa: E402

MM = ROOT / "include" / "mm"
SKIP_DIRS = {"assets", "tables", "text", "overlays", "src"}
SCALARS = {"s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64", "char", "short", "int", "long", "float", "double", "void"}
WORDS = {"unsigned": "u", "signed": "s"}
QUAL = {"const", "volatile", "extern", "register"}


def strip_comments(t: str) -> str:
    t = re.sub(r"/\*.*?\*/", " ", t, flags=re.S)
    t = re.sub(r"//[^\n]*", " ", t)
    return re.sub(r"(?m)^[ \t]*#(?:[^\n]*\\\n)*[^\n]*$", " ", t)   # preprocessor lines, with their continuations


def flatten(t: str):
    """The text with every {...} block taken out: `;` where a function body ended, a marker elsewhere."""
    out, depth = [], 0
    for ch in t:
        if ch == "{":
            if depth == 0:
                out.append(";" if "".join(out).rstrip().endswith(")") else " @ ")
            depth += 1
        elif ch == "}":
            depth -= 1
        elif depth == 0:
            out.append(ch)
    return "".join(out)


class Ref:
    def __init__(self):
        self.typedefs = {}   # name -> ("struct"|"union", tag) | ("enum",) | ("alias", text) | ("fn",)
        self.protos = {}     # function -> (ret text, [arg text], header file)
        self.unk = {}
        for f in sorted(MM.rglob("*.h")):
            if SKIP_DIRS & set(f.relative_to(MM).parts[:-1]):
                continue
            raw = strip_comments(f.read_text(errors="ignore"))
            for m in re.finditer(r"#define\s+(UNK_\w+)\s+(.+)", f.read_text(errors="ignore")):
                self.unk[m.group(1)] = m.group(2).strip()
            self.read_typedefs(raw)
            for st in flatten(raw).split(";"):
                self.read_proto(" ".join(st.split()), f.name)

    def read_typedefs(self, raw: str):
        for m in re.finditer(r"typedef\s+(struct|union)\s*(\w*)\s*(?:\{|(\w+)\s*;)", raw):
            kind, tag, alias = m.groups()
            if alias:   # typedef struct Tag Name;
                self.typedefs.setdefault(alias, (kind, tag))
        text = flatten(re.sub(r"\{", "{", raw))
        for m in re.finditer(r"typedef\s+(struct|union)\s*(\w*)\s*@\s*(\w+)\s*;", text):
            self.typedefs.setdefault(m.group(3), (m.group(1), m.group(2) or m.group(3)))
        for m in re.finditer(r"typedef\s+enum\s*\w*\s*@\s*(\w+)\s*;", text):
            self.typedefs.setdefault(m.group(1), ("enum",))
        for m in re.finditer(r"typedef\s+([^;@()]+?)\s+(\w+)\s*;", text):
            self.typedefs.setdefault(m.group(2), ("alias", m.group(1)))
        for m in re.finditer(r"typedef\s+[^;@]*?\(\s*\*\s*(\w+)\s*\)", text):
            self.typedefs[m.group(1)] = ("fn",)

    def read_proto(self, st: str, header: str):
        m = re.match(r"^(?P<head>[^()=@]*?)\b(?P<name>\w+)\s*\((?P<args>.*)\)$", st)
        if not m or re.search(r"\b(static|typedef|inline)\b", m.group("head")) or m.group("name") in self.protos:
            return
        args, depth, cur = [], 0, ""
        for ch in m.group("args"):
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
            if ch == "," and depth == 0:
                args.append(cur.strip())
                cur = ""
            else:
                cur += ch
        if cur.strip():
            args.append(cur.strip())
        self.protos[m.group("name")] = (m.group("head").strip(), args, header)

    def ctype(self, text: str):
        """(spelling of the type, is it a pointer) or None when the type cannot be spelt without a definition."""
        text = re.sub(r"\b(" + "|".join(self.unk) + r")\b", lambda m: self.unk[m.group(1)], text) if self.unk else text
        stars = text.count("*")
        words = [w for w in re.findall(r"[A-Za-z_]\w*", text) if w not in QUAL]
        if not words or "[" in text:
            return None
        if words[0] in ("struct", "union"):
            return (f"{words[0]} {words[1]} " + "*" * stars, True) if stars else None
        seen = 0
        while len(words) == 1 and words[0] not in SCALARS and seen < 8:
            d = self.typedefs.get(words[0])
            seen += 1
            if d is None or d[0] == "fn":
                return None
            if d[0] == "enum":
                words = ["s32"]
            elif d[0] == "alias":
                words = [w for w in re.findall(r"[A-Za-z_]\w*", d[1]) if w not in QUAL]
                stars += d[1].count("*")
            else:   # a structure: only behind a pointer
                if not stars:
                    return None
                return f"{d[0]} {d[1]} " + "*" * stars, True
        if len(words) > 1 or words[0] in ("long", "short", "int", "char"):   # spelt out: unsigned short, long long...
            u = "unsigned" in words
            rest = [w for w in words if w not in WORDS]
            words = ["char"] if rest == ["char"] and not u and "signed" not in words else \
                    [("u" if u else "s") + ("8" if rest == ["char"] else "16" if rest == ["short"] else "64" if rest == ["long", "long"] else "32")] \
                    if rest in (["char"], ["short"], ["int"], ["long"], ["long", "long"], []) else words
        if len(words) != 1 or words[0] not in SCALARS:
            return None
        if words[0] == "void" and not stars:
            return "void", False
        return f"{words[0]} " + "*" * stars if stars else words[0], stars > 0

    def signature(self, name: str):
        """(ret, [(type, param name)]) fully spelt, or None."""
        if name not in self.protos:
            return None
        head, args, _ = self.protos[name]
        head = re.sub(r"\b(NORETURN|extern)\b", "", head)
        ret = self.ctype(head)
        if ret is None:
            return None
        out = []
        if args == ["void"] or not args:
            return ret, out
        for k, a in enumerate(args):
            if a == "..." or "(" in a:
                return None
            m = re.match(r"^(?P<t>.*?[\s\*])(?P<n>\w+)$", a)
            t, n = (m.group("t"), m.group("n")) if m and not a.rstrip().endswith("*") and m.group("t").strip() not in ("struct", "union", "unsigned", "signed") \
                else (a, f"arg{k}")
            ct = self.ctype(t)
            if ct is None or ct[0] == "void":
                return None
            out.append((ct, n))
        return ret, out


def fmt(name, sig):
    ret, params = sig
    r = ret[0]
    args = ", ".join(f"{t[0]}{'' if t[0].endswith('*') else ' '}{n}" for t, n in params) or "void"
    return f"{r}{'' if r.endswith('*') else ' '}{name}({args})"


def guessed(proto: str):
    """(name, [(type, name)]) of a header line."""
    m = re.match(r"^(?P<ret>.*?[\s\*])(?P<name>\w+)\((?P<args>.*)\);", proto)
    args = [] if m.group("args") in ("", "void") else [tuple(re.match(r"^(.*?[\s\*])(\w+)$", a.strip()).groups()) for a in m.group("args").split(",")]
    return m.group("name"), [(t.strip(), n) for t, n in args]


def agrees(old, ref_params) -> bool:
    """The reference's parameters against the guess read from the assembly (`old`: [(type, name)])."""
    if len(ref_params) < len(old):
        return False
    for (ot, _), ((rt, isptr), _) in zip(old, ref_params):
        if ot in ("f32", "f64") and rt != ot:
            return False
        if "*" in ot and not isptr:
            return False
        if "*" in ot and rt in ("f32", "f64"):
            return False
    return True


def main():
    seg = next(a for a in sys.argv[1:] if not a.startswith("-"))
    jobs = int(sys.argv[sys.argv.index("-j") + 1]) if "-j" in sys.argv else objcache.JOBS
    ref = Ref()
    sig_header.SIGS_FIRST = False
    sigs_file = ROOT / "config" / seg / "sigs.txt"
    old_sigs = sigs_file.read_text() if sigs_file.exists() else None
    if sigs_file.exists():
        sigs_file.unlink()   # the table is made from the guesses, not from itself
    protos = sig_header.build(seg)
    table, retypes, skipped = {}, [], {"no reference prototype": 0, "type not spelt": 0, "assembly disagrees": 0}
    for real, (fn, proto) in sorted(protos.items(), key=lambda kv: kv[1][0]):
        if not re.search(r"\barg\d\b", proto):
            continue
        name, old = guessed(proto)
        if name not in ref.protos:
            skipped["no reference prototype"] += 1
            continue
        sig = ref.signature(name)
        if sig is None:
            skipped["type not spelt"] += 1
            continue
        if not agrees(old, sig[1]):
            skipped["assembly disagrees"] += 1
            continue
        line = fmt(name, sig) + ";"
        table[name] = (fn, line, ref.protos[name][2])
        if retype.source(seg, fn).exists():
            retypes.append((seg, fn, "-", line))
    print(f"{seg}: {len(table)} reference prototypes fit the assembly; skipped " + ", ".join(f"{v} {k}" for k, v in skipped.items()))
    if "--dry" in sys.argv:
        for name, (fn, line, h) in list(table.items())[:40]:
            print("  ", line, "#", h)
        if old_sigs:
            sigs_file.write_text(old_sigs)
        return
    sigs_file.parent.mkdir(parents=True, exist_ok=True)
    sigs_file.write_text("# name prototype  # header of the reference that declares it; made by tools/signatures/ref_sigs.py\n" +
                         "".join(f"{n} {l}  # {h}\n" for n, (fn, l, h) in sorted(table.items(), key=lambda kv: kv[1][0])))
    # the header with the table first, so that a definition retyped to the table's prototype meets the same prototype in the header
    sig_header.SIGS_FIRST = True
    sig_header.write_header(seg, sig_header.build(seg))
    count, why = {}, {}
    with ThreadPoolExecutor(jobs) as ex:
        for (_, fn, _, _), state, reason in ex.map(retype.work, retypes):
            count[state] = count.get(state, 0) + 1
            if state == "failed":
                why[reason] = why.get(reason, 0) + 1
    print("retype: " + " ".join(f"{k}={v}" for k, v in sorted(count.items())))
    for r, n in sorted(why.items(), key=lambda kv: -kv[1]):
        print(f"  failed {n}: {r}")
    sig_header.SIGS_FIRST = False
    sig_header.write_header(seg, sig_header.build(seg))


if __name__ == "__main__":
    main()
