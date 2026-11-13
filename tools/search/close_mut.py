#!/usr/bin/env python3
"""Source-level mutations of one C function, for tools/search/close.py (the adaptive near-miss closer).
Every mutator is `f(text, name) -> iterator of (site, new_text)`: all the ways to apply it once to the function `name` of the file
`text`. The names of the mutators are the keys of the learning statistics (config/search/close_stats.json). A mutation need not
preserve the meaning in every corner: the only judge is the compiler output compared to the ROM, and a match is right by construction.
No `register`, `volatile`, `#pragma` or inline assembly is ever produced (style rules)."""
import re

KEYWORDS = {"if", "else", "for", "while", "do", "switch", "case", "default", "return", "goto", "break", "continue", "typedef", "extern", "static"}
BASIC = r"(?:unsigned |signed )?(?:s8|u8|s16|u16|s32|u32|s64|u64|f32|f64|int|short|char|float|double)"
DECL = re.compile(r"^(?P<ty>" + BASIC + r")(?P<ptr>\s+\**\s*|\s*\*+\s*)(?P<name>[A-Za-z_]\w*)(?P<rest>(?:\[[^\]]*\])?(?:\s*=\s*.+)?);$", re.S)
FLIP = {"<": ">", ">": "<", "<=": ">=", ">=": "<=", "==": "==", "!=": "!="}
NEG = {"<": ">=", ">=": "<", ">": "<=", "<=": ">", "==": "!=", "!=": "=="}
TYPES = ["s32", "u32", "s16", "u16", "s8", "u8", "f32"]
FLAG_SETS = [("-O2", "-g3"), ("-O2", "-g0"), ("-O1", "-g0"), ("-O1", "-g3")]


# ---------------------------------------------------------------- scanning helpers
def skip_lit(t, i):
    """Index after the string, character literal or comment starting at t[i], or i when there is none."""
    if t[i] in "\"'":
        j = i + 1
        while j < len(t) and t[j] != t[i]:
            j += 2 if t[j] == "\\" else 1
        return j + 1
    if t.startswith("//", i):
        j = t.find("\n", i)
        return len(t) if j < 0 else j
    if t.startswith("/*", i):
        j = t.find("*/", i)
        return len(t) if j < 0 else j + 2
    return i


def match_close(t, i):
    """Index of the bracket closing the one at t[i] ('(' '[' '{'), or -1."""
    pair = {"(": ")", "[": "]", "{": "}"}[t[i]]
    depth, j = 0, i
    while j < len(t):
        k = skip_lit(t, j)
        if k != j:
            j = k
            continue
        if t[j] == t[i]:
            depth += 1
        elif t[j] == pair:
            depth -= 1
            if depth == 0:
                return j
        j += 1
    return -1


def top_positions(s, chars):
    """Positions of the characters of `chars` that sit outside every bracket and literal of s."""
    out, depth, i = [], 0, 0
    while i < len(s):
        k = skip_lit(s, i)
        if k != i:
            i = k
            continue
        if s[i] in "([{":
            depth += 1
        elif s[i] in ")]}":
            depth -= 1
        elif depth == 0 and s[i] in chars:
            out.append(i)
        i += 1
    return out


def locate(t, name):
    """(params_start, params_end, body_start, body_end): the text of the body is t[body_start:body_end] (between the braces)."""
    for m in re.finditer(r"\b" + re.escape(name) + r"\s*\(", t):
        close = match_close(t, m.end() - 1)
        if close < 0:
            continue
        m2 = re.match(r"\s*\{", t[close + 1:])
        if m2:
            bs = close + 1 + m2.end()
            return m.end(), close, bs, match_close(t, bs - 1)
    return None


def split_top(s, sep):
    """[(start, end)] of the pieces of s between the top-level occurrences of the operator `sep`."""
    cuts = [p for p in top_positions(s, sep[0]) if s.startswith(sep, p)]
    pieces, start = [], 0
    for p in cuts:
        pieces.append((start, p))
        start = p + len(sep)
    pieces.append((start, len(s)))
    return pieces


def strip_parens(s):
    s = s.strip()
    if s.startswith("(") and match_close(s, 0) == len(s) - 1:
        return s[1:-1]
    return None


def find_cmp(s):
    """(left, op, right) of the first top-level comparison of s, or None."""
    for p in top_positions(s, "<>=!"):
        for op in ("<=", ">=", "==", "!=", "<", ">"):
            if s.startswith(op, p):
                prev = s[p - 1] if p else " "
                if op in "<>" and (prev == "-" or s.startswith(op * 2, p) or prev in "<>"):
                    break
                if op in "<>" and prev in "=!":
                    break
                return s[:p].strip(), op, s[p + len(op):].strip()
    return None


def negate(c):
    c = c.strip()
    inner = strip_parens(c)
    if inner is not None:
        return negate(inner)
    cmp = find_cmp(c)
    if cmp and not top_positions(c, "&|?"):
        return f"{cmp[0]} {NEG[cmp[1]]} {cmp[2]}"
    if c.startswith("!") and not top_positions(c[1:], "&|?=<>"):
        return c[1:].strip()
    return f"!{c}" if re.fullmatch(r"[\w.>\[\]-]+", c) else f"!({c})"


def statements(t, bs, be):
    """[(start, end, kind)] of the simple statements of t[bs:be] (no braces inside, no control keyword first); kind is 'decl' or 'stmt'.
    A statement ending at ';' that opens with a control keyword, or a case label, is not listed."""
    out, start, i, depth = [], bs, bs, 0
    while i < be:
        k = skip_lit(t, i)
        if k != i:
            i = k
            continue
        c = t[i]
        if c in "([":
            depth += 1
        elif c in ")]":
            depth -= 1
        elif depth == 0 and c in "{}":
            start = i + 1
        elif depth == 0 and c == ";":
            text = t[start:i + 1]
            lead = len(text) - len(text.lstrip())
            body = text.strip()
            word = re.match(r"\w+", body)
            if body and not (word and word.group(0) in KEYWORDS) and not re.match(r"\w+\s*:(?!:)", body) and "#" not in body:
                kind = "decl" if DECL.match(body) else "stmt"
                out.append((start + lead, i + 1, kind))
            start = i + 1
        i += 1
    return out


def runs(t, sts):
    """Groups of consecutive statements (only whitespace between them)."""
    groups, cur = [], []
    for s in sts:
        if cur and t[cur[-1][1]:s[0]].strip():
            groups.append(cur)
            cur = []
        cur.append(s)
    return groups + [cur] if cur else groups


def idents(s):
    return set(re.findall(r"[A-Za-z_]\w*", s))


def line_start(t, i):
    return t.rfind("\n", 0, i) + 1


def indent_of(t, i):
    ls = line_start(t, i)
    return re.match(r"[ \t]*", t[ls:]).group(0)


# ---------------------------------------------------------------- mutators
def m_flags(t, name):
    m = re.match(r"// FLAGS: (.*)\n", t)
    cur = m.group(1).split() if m else ["-O2", "-g3", "-mips2"]
    rest = [f for f in cur if f not in ("-O1", "-O2", "-g0", "-g3")]
    for o, g in FLAG_SETS:
        new = [o, g] + rest
        if new != cur:
            body = t[m.end():] if m else t
            yield f"{o} {g}", f"// FLAGS: {' '.join(new)}\n" + body
    for extra in ("-trapuv", "-Wab,-r4300_mul"):   # the second gives the `nop` after every mul.s
        new = [f for f in cur if f != extra] if extra in cur else cur + [extra]
        yield extra, f"// FLAGS: {' '.join(new)}\n" + (t[m.end():] if m else t)


def m_cmp_swap(t, name):
    for tag, site, new in cond_edits(t, name, only="cmp_swap"):
        yield site, new


def m_not_form(t, name):
    for tag, site, new in cond_edits(t, name, only="not_form"):
        yield site, new


def m_cmp_const(t, name):
    for tag, site, new in cond_edits(t, name, only="cmp_const"):
        yield site, new


def m_bool_swap(t, name):
    for tag, site, new in cond_edits(t, name, only="bool_swap"):
        yield site, new


def expr_sites(t, bs, be):
    """[(label, start, end)] of the expressions worth rewriting: the conditions of if/while/for, the operand of return, the right side
    of an assignment and every parenthesised group that is not a call or a cast."""
    for m in re.finditer(r"\b(if|while|for)\s*\(", t[bs:be]):
        a = bs + m.end() - 1
        b = match_close(t, a)
        if b < 0 or b > be:
            continue
        cs, ce = a + 1, b
        if m.group(1) == "for":
            semis = top_positions(t[cs:ce], ";")
            if len(semis) != 2:
                continue
            cs, ce = cs + semis[0] + 1, cs + semis[1]
        yield m.group(1), cs, ce
    for m in re.finditer(r"\breturn\s+([^;]+);", t[bs:be]):
        yield "return", bs + m.start(1), bs + m.end(1)
    for a, b, k in statements(t, bs, be):
        eq = [p for p in top_positions(t[a:b], "=") if not t[a + p + 1:a + p + 2] == "=" and t[a + p - 1:a + p] not in "=!<>+-*/&|^%"]
        if eq:
            yield "rhs", a + eq[0] + 1, b - 1
    for m in re.finditer(r"\(", t[bs:be]):
        a = bs + m.start()
        prev = t[:a].rstrip()[-1:]
        b = match_close(t, a)
        inner = t[a + 1:b]
        if (prev.isalnum() or prev == "_") or b < 0 or b > be or re.fullmatch(r"\s*(?:unsigned |signed )?\w+\s*\**\s*", inner):
            continue
        yield "paren", a + 1, b


def cond_edits(t, name, only=None):
    loc = locate(t, name)
    if not loc:
        return
    seen = set()
    for label, cs, ce in expr_sites(t, loc[2], loc[3]):
        for tag, new in cond_variants(t[cs:ce]):
            if only and tag != only:
                continue
            text = t[:cs] + new + t[ce:]
            if text not in seen:
                seen.add(text)
                yield tag, f"{label}@{cs}", text


def arith_variants(s):
    """Operands of a commutative operator swapped (a + b + c: each neighbouring pair), and the same inside every term."""
    if top_positions(s, "?"):
        return
    ops = binary_ops(s)
    if not ops:
        return
    low = [o for o in ops if o[1] in ("+", "-")] or [o for o in ops if o[1] in ("*", "/", "%")] or ops
    cuts = [(p, o) for p, o in low]
    bounds = [(0 if k == 0 else cuts[k - 1][0] + len(cuts[k - 1][1]), cuts[k][0] if k < len(cuts) else len(s)) for k in range(len(cuts) + 1)]
    kinds = {o for _, o in cuts}
    for k, (a, b) in enumerate(bounds):
        for tag, new in cond_variants(s[a:b]):
            yield tag, s[:a] + (" " if s[a:a + 1] == " " else "") + new.strip() + s[b:]
    if len(kinds) == 1 and kinds <= {"+", "*", "&", "|", "^"}:
        o = next(iter(kinds))
        for k in range(len(bounds) - 1):
            (a, b), (c, d) = bounds[k], bounds[k + 1]
            yield "commute", s[:a] + s[c:d].strip() + f" {o} " + s[a:b].strip() + s[d:]


def cond_variants(c):
    s = c.strip()
    lead = c[:len(c) - len(c.lstrip())]
    trail = c[len(c.rstrip()):]
    for op in ("||", "&&"):
        parts = split_top(s, op)
        if len(parts) > 1:
            for i, (a, b) in enumerate(parts):
                for tag, new in cond_variants(s[a:b]):
                    yield tag, lead + s[:a] + new.strip() + s[b:] + trail
                if i + 1 < len(parts):   # a && b <-> b && a (short-circuit order)
                    na, nb = parts[i + 1]
                    yield "bool_swap", lead + s[:a] + s[na:nb].strip() + f" {op} " + s[a:b].strip() + s[nb:] + trail
            return
    inner = strip_parens(s)
    if inner is not None:
        for tag, new in cond_variants(inner):
            yield tag, lead + "(" + new.strip() + ")" + trail
        return
    cmp = find_cmp(s)
    if cmp:
        l, op, r = cmp
        yield "cmp_swap", f"{lead}{r} {FLIP[op]} {l}{trail}"
        if op in ("==", "!=") and r == "0":
            yield "not_form", lead + (f"!{l}" if op == "==" and re.fullmatch(r"[\w.>\[\]-]+", l) else f"!({l})" if op == "==" else l) + trail
        if op in ("<", ">", "<=", ">=") and re.fullmatch(r"-?\d+", r):
            n = int(r)
            alt = {"<": ("<=", n - 1), "<=": ("<", n + 1), ">": (">=", n + 1), ">=": (">", n - 1)}[op]
            yield "cmp_const", f"{lead}{l} {alt[0]} {alt[1]}{trail}"
        for tag, new in arith_variants(l):
            yield tag, f"{lead}{new.strip()} {op} {r}{trail}"
        for tag, new in arith_variants(r):
            yield tag, f"{lead}{l} {op} {new.strip()}{trail}"
    elif s.startswith("!") and not top_positions(s[1:], "&|?=<>"):
        yield "not_form", f"{lead}{s[1:].strip()} == 0{trail}"
    elif re.fullmatch(r"[\w.>\[\]-]+", s):
        yield "not_form", f"{lead}{s} != 0{trail}"
    else:
        for tag, new in arith_variants(s):
            yield tag, lead + new.strip() + trail


def blocks_if_else(t, bs, be):
    """[(if_start, cond_span, then_span, else_span)] of every `if (c) {..} else {..}` of the body (else-if chains are skipped)."""
    out = []
    for m in re.finditer(r"\bif\s*\(", t[bs:be]):
        a = bs + m.end() - 1
        b = match_close(t, a)
        m2 = re.match(r"\s*\{", t[b + 1:]) if b > 0 else None
        if not m2:
            continue
        ts = b + 1 + m2.end()
        te = match_close(t, ts - 1)
        m3 = re.match(r"\s*else\s*\{", t[te + 1:]) if te > 0 else None
        if not m3:
            continue
        es = te + 1 + m3.end()
        ee = match_close(t, es - 1)
        if ee > 0:
            out.append((bs + m.start(), (a + 1, b), (ts, te), (es, ee)))
    return out


def m_if_swap(t, name):
    """`if (c) {A} else {B}` -> `if (!c) {B} else {A}`."""
    loc = locate(t, name)
    for st, (cs, ce), (ts, te), (es, ee) in blocks_if_else(t, loc[2], loc[3]) if loc else []:
        yield f"@{st}", t[:cs] + negate(t[cs:ce]) + t[ce:ts] + t[es:ee] + t[te:es] + t[ts:te] + t[ee:]


def ends_in_exit(block):
    return bool(re.search(r"(?:\breturn\b[^;]*|\bbreak|\bcontinue|\bgoto \w+);\s*$", block))


def m_drop_else(t, name):
    """`if (c) {..return;} else {B}` -> `if (c) {..return;} B`."""
    loc = locate(t, name)
    for st, (cs, ce), (ts, te), (es, ee) in blocks_if_else(t, loc[2], loc[3]) if loc else []:
        if ends_in_exit(t[ts:te]):
            yield f"@{st}", t[:te + 1] + "\n" + t[es:ee].strip("\n") + t[ee + 1:]


def m_add_else(t, name):
    """`if (c) {..return;} REST` -> `if (c) {..return;} else {REST}` (REST up to the end of the enclosing block)."""
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    for m in re.finditer(r"\bif\s*\(", t[bs:be]):
        a = bs + m.end() - 1
        b = match_close(t, a)
        m2 = re.match(r"\s*\{", t[b + 1:]) if b > 0 else None
        if not m2:
            continue
        ts = b + 1 + m2.end()
        te = match_close(t, ts - 1)
        if te < 0 or re.match(r"\s*else\b", t[te + 1:]) or not ends_in_exit(t[ts:te]):
            continue
        end, depth = te + 1, 0   # end of the enclosing block
        while end < be:
            k = skip_lit(t, end)
            if k != end:
                end = k
                continue
            if t[end] == "{":
                depth += 1
            elif t[end] == "}":
                if depth == 0:
                    break
                depth -= 1
            end += 1
        rest = t[te + 1:end]
        if rest.strip() and not re.match(r"\s*(case|default)\b", rest):
            ind = indent_of(t, bs + m.start())
            yield f"@{bs + m.start()}", t[:te + 1] + " else {" + rest.rstrip() + "\n" + ind + "}\n" + t[end:]


def m_dup_return(t, name):
    """`if (c) {A} else {B} return x;` -> the `return x;` at the end of both branches (the ROM repeats the epilogue)."""
    loc = locate(t, name)
    for st, (cs, ce), (ts, te), (es, ee) in blocks_if_else(t, loc[2], loc[3]) if loc else []:
        ret = re.match(r"\s*(return\b[^;]*;)", t[ee + 1:])
        if ret and not ends_in_exit(t[ts:te]) and not ends_in_exit(t[es:ee]):
            ind, x = indent_of(t, st), ret.group(1)
            tail = "\n" + ind + "    " + x + "\n" + ind
            yield f"@{st}", t[:te].rstrip() + tail + t[te:ee].rstrip() + tail + t[ee] + t[ee + 1 + ret.end():]


def m_stmt_swap(t, name):
    loc = locate(t, name)
    if not loc:
        return
    for g in runs(t, [s for s in statements(t, loc[2], loc[3]) if s[2] == "stmt"]):
        for i in range(len(g) - 1):
            (a, b, _), (c, d, _) = g[i], g[i + 1]
            yield f"@{a}", t[:a] + t[c:d] + t[b:c] + t[a:b] + t[d:]
        for i in range(len(g)):   # hoist a statement up by two or more places
            for j in range(i + 2, len(g)):
                (a, b, _), (c, d, _) = g[i], g[j]
                yield f"@{c}<{a}", t[:a] + t[c:d] + "\n" + indent_of(t, a) + t[a:c].rstrip() + t[d:]


def m_decl_swap(t, name):
    loc = locate(t, name)
    if not loc:
        return
    for g in runs(t, [s for s in statements(t, loc[2], loc[3]) if s[2] == "decl"]):
        for i in range(len(g) - 1):
            (a, b, _), (c, d, _) = g[i], g[i + 1]
            yield f"@{a}", t[:a] + t[c:d] + t[b:c] + t[a:b] + t[d:]
        for i in range(len(g)):   # to the front / to the back of the declarations
            a, b, _ = g[i]
            if i:
                yield f"first@{a}", t[:g[0][0]] + t[a:b] + "\n" + indent_of(t, g[0][0]) + t[g[0][0]:a].rstrip() + t[b:]
            if i < len(g) - 1:
                e = g[-1][1]
                yield f"last@{a}", t[:a] + t[b:e].lstrip() + "\n" + indent_of(t, a) + t[a:b] + t[e:]


def m_pad(t, name):
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    decls = [s for s in statements(t, bs, be) if s[2] == "decl"]
    ind = indent_of(t, decls[0][0]) if decls else "    "
    for pad in ("s32 pad;", "s32 pad2[2];", "s32 pad4[4];", "s16 pad_h;"):
        if decls:
            yield f"first:{pad}", t[:decls[0][0]] + pad + "\n" + ind + t[decls[0][0]:]
            e = decls[-1][1]
            yield f"last:{pad}", t[:e] + "\n" + ind + pad + t[e:]
        else:
            yield f"first:{pad}", t[:bs] + "\n" + ind + pad + "\n" + t[bs:]
    for a, b, k in decls:   # drop a padding or an unused local
        mm = DECL.match(t[a:b])
        if mm and len(re.findall(r"\b" + mm.group("name") + r"\b", t[bs:be])) == 1:
            ls = line_start(t, a)
            alone = t[ls:a].strip() == ""
            yield f"drop {mm.group('name')}", (t[:ls] + t[b:].lstrip(" ").lstrip("\n")) if alone else t[:a] + t[b:]


def m_local_type(t, name):
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    for a, b, k in statements(t, bs, be):
        mm = DECL.match(t[a:b]) if k == "decl" else None
        if mm:
            for ty in TYPES:
                if ty != mm.group("ty"):
                    yield f"{mm.group('name')}:{ty}", t[:a] + ty + t[a + len(mm.group("ty")):]
    pa, pb = loc[0], loc[1]
    off = pa
    for p in t[pa:pb].split(","):
        mm = re.match(r"(\s*)(" + BASIC + r")(\s+\**\s*\w+\s*)$", p)
        if mm:
            for ty in TYPES:
                if ty != mm.group(2):
                    s0 = off + len(mm.group(1))
                    yield f"param {mm.group(3).strip()}:{ty}", t[:s0] + ty + t[s0 + len(mm.group(2)):]
        off += len(p) + 1


def m_param(t, name):
    loc = locate(t, name)
    if not loc:
        return
    pa, pb, bs, be = loc
    params = t[pa:pb]
    plist = [] if params.strip() in ("", "void") else [p.strip() for p in params.split(",")]
    if len(plist) < 5:
        yield f"add{len(plist)}", t[:pa] + ", ".join(plist + [f"s32 arg{len(plist)}x"]) + t[pb:]
    if plist:
        last = re.search(r"(\w+)\s*$", plist[-1])
        if last and not re.search(r"\b" + last.group(1) + r"\b", t[bs:be]):
            yield f"drop{len(plist) - 1}", t[:pa] + (", ".join(plist[:-1]) or "void") + t[pb:]


def m_alias(t, name):
    """A pointer parameter copied to a local that the body then uses (`T *this = thisx;`)."""
    loc = locate(t, name)
    if not loc or re.search(r"\bthis\b", t[loc[2]:loc[3]]):
        return
    pa, pb, bs, be = loc
    for p in t[pa:pb].split(","):
        mm = re.match(r"\s*([A-Za-z_]\w*)\s*(\*)\s*([A-Za-z_]\w*)\s*$", p)
        if mm:
            ty, par = mm.group(1), mm.group(3)
            body = re.sub(r"\b" + par + r"\b", "this", t[bs:be])
            if body != t[bs:be]:
                decls = [s for s in statements(t, bs, be) if s[2] == "decl"]
                at = decls[0][0] if decls else bs
                ind = indent_of(t, at) if decls else "    "
                line = f"{ty} *this = {par};\n{ind}"
                cut = at - bs
                yield par, t[:bs] + (body[:cut] + line + body[cut:] if decls else "\n" + ind + line.rstrip() + body) + t[be:]


def m_inline_local(t, name):
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    body = t[bs:be]
    declared = {DECL.match(t[a:b]).group("name") for a, b, k in statements(t, bs, be) if k == "decl"}
    for a, b, k in statements(t, bs, be):
        text = t[a:b]
        mm = DECL.match(text)
        var = rhs = None
        if mm and re.match(r"\s*=\s*", mm.group("rest")):
            var, rhs = mm.group("name"), re.sub(r"^\s*=\s*", "", mm.group("rest"))
        elif k == "stmt":
            m2 = re.match(r"([A-Za-z_]\w*)\s*=\s*([^=].*);$", text, re.S)
            if m2 and m2.group(1) in declared and not text.startswith(m2.group(1) + " ==") and not re.search(r"\b" + m2.group(1) + r"\b", m2.group(2)):
                var, rhs = m2.group(1), m2.group(2)
        if not var:
            continue
        rhs = rhs.rstrip(";").strip()
        assigns = re.findall(r"\b" + var + r"\s*(?:[-+*/&|^]|<<|>>)?=(?!=)|\+\+\s*" + var + r"|\b" + var + r"\s*\+\+|--\s*" + var + r"|\b" + var + r"\s*--", body)
        bare = [s for s in statements(t, bs, be) if s[2] == "decl" and re.fullmatch(r"[^=]*\b" + var + r"\s*;", t[s[0]:s[1]])]   # `T x;`
        uses = len(re.findall(r"\b" + var + r"\b", body)) - len(assigns) - len(bare)
        if len(assigns) != 1 or uses < 1:
            continue
        simple = bool(re.fullmatch(r"[\w.>\[\]*&-]+|\([\w ]+\*?\)\s*[\w.>\[\]-]+", rhs))
        # a read of one field (`M2C_FIELD(p, s16 *, 0x16)`, no call): every use becomes the read again, as the ROM loads it again each time
        field = rhs.startswith("M2C_FIELD(") and match_close(rhs, 9) == len(rhs) - 1 and set(re.findall(r"([A-Za-z_]\w*)\s*\(", rhs)) == {"M2C_FIELD"}
        if not simple and not field and uses != 1:
            continue
        sub = rhs if simple or field else f"({rhs})"
        rest = re.sub(r"\b" + var + r"\b", lambda _: sub, t[b:be]) + t[be:]
        ls = line_start(t, a)
        new = (t[:ls] + rest.lstrip(" ").lstrip("\n")) if t[ls:a].strip() == "" else t[:a] + rest
        for da, db, _ in bare:   # the declaration without initialiser goes too
            if db < a and new[line_start(new, da):da].strip() == "":
                new = new[:line_start(new, da)] + new[db:].lstrip(" ").lstrip("\n")
        yield var, new


LATE = re.compile(r"(?P<ind>[ \t]*)(?:(?P<ty>[A-Za-z_]\w*\s*\*+)\s*(?P<v>[A-Za-z_]\w*)\s*=|(?P<v2>[A-Za-z_]\w*)\s*=(?!=))\s*(?P<e>[^;=]+);\s*\n"
                  r"(?P<ind2>[ \t]*)if \((?P<c>[A-Za-z_]\w*)(?: != (?:0|NULL))?\) \{")


def m_late_local(t, name):
    """`T *x = E; if (x != 0) {` becomes `T *x; if (E != 0) { x = E;`: the local is assigned after the test of the expression (the ROM
    then keeps the loaded value and the local in two registers, and the local takes the second one)."""
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    for m in LATE.finditer(t[bs:be]):
        v = m.group("v") or m.group("v2")
        if m.group("c") != v:
            continue
        e, ty, a, b = m.group("e").strip(), m.group("ty"), bs + m.start(), bs + m.end()
        base = re.sub(r"\s+", "", ty)[:-1] if ty else ""
        head = f"{m.group('ind')}{base} *{v};\n" if ty else ""
        yield f"{v}@{a}", t[:a] + head + f"{m.group('ind2')}if ({e} != 0) {{\n{m.group('ind2')}    {v} = {e};" + t[b:]


def m_extract(t, name):
    """A repeated field/array expression becomes a local (`s32 temp = a->b;`)."""
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    body = t[bs:be]
    cands = {}
    for m in re.finditer(r"\b[A-Za-z_]\w*(?:->\w+|\.\w+|\[[^\]\[]+\])+", body):
        cands[m.group(0)] = cands.get(m.group(0), 0) + 1
    exprs = sorted((e for e, n in cands.items() if n >= 2), key=lambda e: (-cands[e], -len(e)))[:4]
    decls = [s for s in statements(t, bs, be) if s[2] == "decl"]
    for k, e in enumerate(exprs):
        var = f"temp{k}"
        if re.search(r"\b" + var + r"\b", body):
            continue
        first = bs + body.index(e)
        ind = indent_of(t, first)
        ls = line_start(t, first)
        for ty in ("s32", "f32", "u32"):
            put = f"{ind}{var} = {e};\n"
            new = t[:ls] + put + t[ls:].replace(e, var)
            if decls:
                dl = decls[-1][1]
                new = new[:dl] + f"\n{indent_of(new, decls[0][0])}{ty} {var};" + new[dl:]
            else:
                new = new[:bs] + f"\n    {ty} {var};\n" + new[bs:]
            yield f"{e}:{ty}", new


def m_chain_assign(t, name):
    loc = locate(t, name)
    if not loc:
        return
    sts = [s for s in statements(t, loc[2], loc[3]) if s[2] == "stmt"]
    for g in runs(t, sts):
        for i in range(len(g) - 1):
            (a, b, _), (c, d, _) = g[i], g[i + 1]
            m1 = re.fullmatch(r"([^=;]+?)\s*=\s*([^=;]+);", t[a:b])
            m2 = re.fullmatch(r"([^=;]+?)\s*=\s*([^=;]+);", t[c:d])
            if m1 and m2 and m1.group(2).strip() == m2.group(2).strip():
                yield f"merge@{a}", t[:a] + f"{m1.group(1)} = {m2.group(1)} = {m1.group(2).strip()};" + t[d:]
                yield f"merge_r@{a}", t[:a] + f"{m2.group(1)} = {m1.group(1)} = {m1.group(2).strip()};" + t[d:]
    for a, b, _ in sts:
        m = re.fullmatch(r"([^=;]+?)\s*=\s*([^=;]+?)\s*=\s*([^=;]+);", t[a:b])
        if m:
            ind = indent_of(t, a)
            yield f"split@{a}", t[:a] + f"{m.group(2)} = {m.group(3)};\n{ind}{m.group(1)} = {m.group(3)};" + t[b:]
            yield f"split_r@{a}", t[:a] + f"{m.group(1)} = {m.group(3)};\n{ind}{m.group(2)} = {m.group(3)};" + t[b:]


def binary_ops(s):
    """[(pos, op)] of the top-level binary operators of the expression s."""
    out = []
    for p in top_positions(s, "+-*/%&|^<>"):
        prev = s[:p].rstrip()
        if not prev or not (prev[-1].isalnum() or prev[-1] in ")]_"):
            continue
        if s[p] in "&|" and s.startswith(s[p] * 2, p) or (s[p] in "&|" and p and s[p - 1] == s[p]):
            out.append((p, s[p] * 2))
        elif s.startswith("->", p) or (s[p] == ">" and p and s[p - 1] == "-"):
            continue
        else:
            out.append((p, s[p]))
    return out


def m_commute(t, name):
    for tag, site, new in cond_edits(t, name, only="commute"):
        yield site, new


def m_float_lit(t, name):
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    for m in re.finditer(r"(?<![\w.])(\d+\.\d*|\d+)(f?)(?![\w.])", t[bs:be]):
        a, b = bs + m.start(), bs + m.end()
        lit, f = m.group(1), m.group(2)
        if "." in lit:
            yield f"{m.group(0)}", t[:a] + lit + ("" if f else "f") + t[b:]
            if lit.endswith(".0") or lit.endswith("."):
                yield f"{m.group(0)}->int", t[:a] + str(int(float(lit))) + t[b:]
        elif lit in ("0", "1", "2") and not f and not t[max(bs, a - 1):a] in ("[", "x"):
            yield f"{lit}->float", t[:a] + lit + ".0f" + t[b:]


def f32_text(bits):
    """The shortest decimal literal that is exactly the f32 with these bits (`0.1f`), or None for a NaN or an infinity."""
    import struct
    v = struct.unpack(">f", struct.pack(">I", bits))[0]
    if v != v or v in (float("inf"), float("-inf")):
        return None
    for prec in range(1, 10):
        s = "%.*g" % (prec, v)
        if struct.pack(">f", float(s)) == struct.pack(">f", v):
            break
    if "e" in s and "." not in s.split("e")[0]:
        s = s.replace("e", ".0e")
    elif "e" not in s and "." not in s:
        s += ".0"
    return s + "f"


def m_callf32(t, name):
    """An argument that is the bit pattern of a float (`0x3C23D70A`) or a `0` goes to a callee whose parameter is an f32: the literal is
    written as a float and the parameter of the prototype becomes f32 (IDO then passes it in an integer register after a pointer
    argument, which is what `addiu a1, zero, 0` and `lui a1, 0x3C23` in the ROM are)."""
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    head = t[:loc[0]]
    for m in re.finditer(r"\b([A-Za-z_]\w*)\s*\(", t[bs:be]):
        callee = m.group(1)
        if callee in KEYWORDS or callee == name:
            continue
        a = bs + m.end() - 1
        b = match_close(t, a)
        if b < 0:
            continue
        inner = t[a + 1:b]
        pieces = [(s, e) for s, e in split_top(inner, ",")] if inner.strip() else []
        pr = re.search(r"^([^\n;(]*\b" + re.escape(callee) + r"\s*\()([^)]*)(\)\s*;.*)$", head, re.M)
        if not pr:
            continue
        params = [x.strip() for x in pr.group(2).split(",")] if pr.group(2).strip() not in ("", "void") else []
        if len(params) < len(pieces):
            params += ["s32"] * (len(pieces) - len(params))
        for i, (s, e) in enumerate(pieces):
            arg = inner[s:e].strip()
            if re.fullmatch(r"0x[0-9A-Fa-f]{8}", arg) and 0x20000000 <= int(arg, 16) < 0xC8000000 and f32_text(int(arg, 16)):
                lit = f32_text(int(arg, 16))
            elif arg == "0":
                lit = "0.0f"
            else:
                continue
            np_ = params[:]
            np_[i] = "f32"
            ns = a + 1 + s + (len(inner[s:e]) - len(inner[s:e].lstrip()))
            ne = a + 1 + s + len(inner[s:e].rstrip())
            body = t[:ns] + lit + t[ne:]
            # the prototype sits before the function: its offsets do not move the body text edit (same length change on both sides is irrelevant)
            h0 = pr.start(2)
            h1 = pr.end(2)
            yield f"{callee}#{i}", body[:h0] + ", ".join(np_) + body[h1:]


def m_fwdarg(t, name):
    """A parameter of the function is passed on to a callee that the draft gives fewer arguments (the ROM leaves `a0` untouched across the
    call and sets `a1`: the callee takes `(arg0, x)`): `f(x)` -> `f(arg0, x)` at every position, the prototype gets the parameter too."""
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    head = t[:loc[0]]
    ptxt = t[loc[0]:loc[1]]
    plist = [x.strip() for x in ptxt.split(",")] if ptxt.strip() not in ("", "void") else []
    pn = []
    for x in plist:
        mm = re.search(r"(\w+)\s*$", x)
        if mm and mm.group(1) not in BASIC.split("|"):
            pn.append((mm.group(1), x[:mm.start()].strip()))
    if not pn:
        return
    for m in re.finditer(r"\b(func_[0-9A-Fa-f]{8})\s*\(", t[bs:be]):
        callee = m.group(1)
        a = bs + m.end() - 1
        b = match_close(t, a)
        if b < 0:
            continue
        inner = t[a + 1:b]
        args = [inner[s:e].strip() for s, e in split_top(inner, ",")] if inner.strip() else []
        pr = re.search(r"^([^\n;(]*\b" + re.escape(callee) + r"\s*\()([^)]*)(\)\s*;.*)$", head, re.M)
        if not pr:
            continue
        params = [x.strip() for x in pr.group(2).split(",")] if pr.group(2).strip() not in ("", "void") else []
        for k in range(2, len(pn) + 1):   # the first k parameters together: `f()` -> `f(arg0, arg1)`
            if not args and k <= 4 and not any(n in args for n, _ in pn[:k]):
                np_ = params[:]
                if np_ or pr.group(2).strip() == "":
                    np_ = [ty or "s32" for _, ty in pn[:k]] + np_ if np_ else []
                body = t[:a + 1] + ", ".join(n for n, _ in pn[:k]) + t[b:]
                yield f"{callee}+first{k}", body[:pr.start(2)] + ", ".join(np_) + body[pr.end(2):]
        for ai, (an, aty) in enumerate(pn):
            if an in args or len(args) >= 4:
                continue
            for pos in range(len(args) + 1):
                nargs = args[:pos] + [an] + args[pos:]
                np_ = params[:]
                if np_:
                    np_.insert(min(pos, len(np_)), aty or "s32")
                body = t[:a + 1] + ", ".join(nargs) + t[b:]
                yield f"{callee}+{an}@{pos}", body[:pr.start(2)] + ", ".join(np_) + body[pr.end(2):]


def m_fieldsign(t, name):
    """`M2C_FIELD(x, s8 *, 0xB6)` <-> `u8 *` (and 16, 32 bits): the signedness of one raw field access (`addiu -1` against `addiu 255`)."""
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    flip = {"s8": "u8", "u8": "s8", "s16": "u16", "u16": "s16", "s32": "u32", "u32": "s32"}
    for m in re.finditer(r"M2C_FIELD\([^;]*?,\s*(s8|u8|s16|u16|s32|u32)\s*\*\s*,", t[bs:be]):
        a = bs + m.start(1)
        yield f"@{a}", t[:a] + flip[m.group(1)] + t[a + len(m.group(1)):]


def m_index(t, name):
    """`M2C_FIELD((p + (i * 4)), s32 *, 0x800)` -> `((s32 *)(p + 0x800))[i]`: an array element (`addu base, index` in that order)."""
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    size = {"s8": 1, "u8": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "f32": 4}
    for m in re.finditer(r"M2C_FIELD\(", t[bs:be]):
        a = bs + m.end() - 1
        b = match_close(t, a)
        if b < 0:
            continue
        inner = t[a + 1:b]
        cuts = split_top(inner, ",")
        if len(cuts) != 3:
            continue
        base, ty, off = (inner[s:e].strip() for s, e in cuts)
        tm = re.fullmatch(r"(s8|u8|s16|u16|s32|u32|f32) \*", ty) or re.fullmatch(r"(\w+ \*+)\*", ty)   # a pointer element (`u8 **`) is 4 bytes
        if not tm:
            continue
        bb = strip_parens(base) or base
        parts = split_top(bb, " + ")
        if len(parts) != 2:
            continue
        p0, p1 = (bb[s:e].strip() for s, e in parts)
        p1 = strip_parens(p1) or p1
        mul = split_top(p1, " * ")
        if len(mul) != 2:
            continue
        idx, n = (p1[s:e].strip() for s, e in mul)
        if not n.isdigit() or int(n) != size.get(tm.group(1), 4):
            continue
        yield f"@{a}", t[:bs + m.start()] + f"(({ty})({p0} + {off}))[{idx}]" + t[b + 1:]


def m_symarr(t, name):
    """`*(&D_8000 + (i * 4))` -> `D_8000[i]` with `extern s32 D_8000[];` (an array of a data symbol; the element type from the stride)."""
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    types = {1: ["u8", "s8"], 2: ["s16", "u16"], 4: ["s32", "u32", "f32"], 8: ["f64"]}
    for m in re.finditer(r"\*\(&([A-Za-z_]\w*) \+ ", t[bs:be]):
        a = bs + m.end()
        k = match_close(t, bs + m.start() + 1)
        if k < 0:
            continue
        rest = t[a:k]                       # "E * N" or "(E * N)" or "E"
        body = strip_parens(rest) or rest
        mul = split_top(body, " * ")
        if len(mul) == 2 and body[mul[1][0]:mul[1][1]].strip().isdigit():
            idx, n = body[mul[0][0]:mul[0][1]].strip(), int(body[mul[1][0]:mul[1][1]].strip())
        else:
            idx, n = body.strip(), 1
        decl = re.search(r"^extern\s+(?:M2C_UNK|s32|u32|s8|u8|s16|u16|f32)\s+" + re.escape(m.group(1)) + r"(\[\])?;", t, re.M)
        for ty in types.get(n, []):
            new = t[:bs + m.start()] + f"{m.group(1)}[{idx}]" + t[k + 1:]
            if decl:
                new = new[:decl.start()] + f"extern {ty} {m.group(1)}[];" + new[decl.end():]
            elif not re.search(r"\b" + re.escape(m.group(1)) + r"\[\]", t):
                continue
            yield f"{m.group(1)}:{ty}", new


def m_retfold(t, name):
    """`T v; v = A; if (C) { v = B; } return v;` -> `if (C) { return B; } return A;` (and with an else: `if (C) { return B; } else { return A; }`)."""
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    pat = re.compile(r"(?P<d>[ \t]*(?:s8|u8|s16|u16|s32|u32|f32)\s+(?P<v>\w+);\n)?(?P<i>[ \t]*)(?P=v)\s*=\s*(?P<a>[^;\n]+);\n[ \t]*if \((?P<c>[^\n]+)\) \{\n\s*(?P=v) = (?P<b>[^;\n]+);\n\s*\}\n[ \t]*return (?P=v);")
    for m in pat.finditer(t[bs:be]):
        a, b = bs + m.start(), bs + m.end()
        ind = m.group("i")
        yield f"@{a}", t[:a] + f"{ind}if ({m.group('c')}) {{\n{ind}    return {m.group('b')};\n{ind}}}\n{ind}return {m.group('a')};" + t[b:]


def m_dropsp(t, name):
    """m2c's `spNN` locals (a copy kept on the stack, written and never read): the declaration and its assignments are removed."""
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    body = t[bs:be]
    for m in re.finditer(r"^[ \t]*(?:s8|u8|s16|u16|s32|u32|f32|f64|M2C_UNK)\s+\*?(sp[0-9A-Fa-f]+);\n", body, re.M):
        v = m.group(1)
        rest = body[:m.start()] + body[m.end():]
        stripped = re.sub(r"^[ \t]*" + v + r" = [^;\n]*;\n", "", rest, flags=re.M)
        if re.search(r"\b" + v + r"\b", stripped):
            continue
        yield v, t[:bs] + stripped + t[be:]


def m_cast(t, name):
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    for m in re.finditer(r"\(\s*(?:s8|u8|s16|u16|s32|u32|f32|f64)\s*\**\s*\)\s*", t[bs:be]):
        yield f"{m.group(0).strip()}@{bs + m.start()}", t[:bs + m.start()] + t[bs + m.end():]


def m_addu(t, name):
    """`p + n` -> `(u8 *)((s32)p + n)` (the order of the operands of addu)."""
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    for m in re.finditer(r"(?<![\w>.])([A-Za-z_]\w*) \+ (0x[0-9A-Fa-f]+|\d+|[A-Za-z_]\w*)(?![\w(\[])", t[bs:be]):
        yield f"@{bs + m.start()}", t[:bs + m.start()] + f"(u8 *)((s32){m.group(1)} + {m.group(2)})" + t[bs + m.end():]
    for m in re.finditer(r"(?<![\w>.])([A-Za-z_]\w*) \+ \(", t[bs:be]):   # `p + (expr)`: the right operand is a bracketed expression
        j = bs + m.end() - 1
        k = match_close(t, j)
        if k > 0:
            yield f"@{bs + m.start()}p", t[:bs + m.start()] + f"(u8 *)((s32){m.group(1)} + {t[j:k + 1]})" + t[k + 1:]
            yield f"@{bs + m.start()}s", t[:bs + m.start()] + f"{t[j:k + 1]} + {m.group(1)}" + t[k + 1:]


def m_ternary(t, name):
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    for m in re.finditer(r"if \((?P<c>[^{};]+)\) \{\s*(?P<x>[^;={}]+?) = (?P<a>[^;{}]+);\s*\} else \{\s*(?P=x) = (?P<b>[^;{}]+);\s*\}", t[bs:be]):
        a, b = bs + m.start(), bs + m.end()
        yield f"if2tern@{a}", t[:a] + f"{m.group('x')} = {m.group('c')} ? {m.group('a')} : {m.group('b')};" + t[b:]
    for a, b, k in statements(t, bs, be):
        mm = re.fullmatch(r"([^=;?]+?)\s*=\s*([^;?]+?)\s*\?\s*([^;:?]+?)\s*:\s*([^;?]+?);", t[a:b])
        if mm:
            ind = indent_of(t, a)
            yield f"tern2if@{a}", t[:a] + f"if ({mm.group(2)}) {{\n{ind}    {mm.group(1)} = {mm.group(3)};\n{ind}}} else {{\n{ind}    {mm.group(1)} = {mm.group(4)};\n{ind}}}" + t[b:]


def m_loop(t, name):
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    for m in re.finditer(r"\bfor\s*\(", t[bs:be]):
        a = bs + m.end() - 1
        b = match_close(t, a)
        parts = top_positions(t[a + 1:b], ";")
        m2 = re.match(r"\s*\{", t[b + 1:])
        if len(parts) != 2 or not m2:
            continue
        inner = t[a + 1:b]
        init, cond, step = inner[:parts[0]].strip(), inner[parts[0] + 1:parts[1]].strip(), inner[parts[1] + 1:].strip()
        ts = b + 1 + m2.end()
        te = match_close(t, ts - 1)
        ind = indent_of(t, bs + m.start())
        head = (init + ";\n" + ind) if init else ""
        tail = (ind + "    " + step + ";\n" + ind) if step else ind
        yield f"for2while@{a}", t[:bs + m.start()] + head + f"while ({cond or '1'}) {{" + t[ts:te].rstrip() + "\n" + tail + t[te:]
    for m in re.finditer(r"\bwhile\s*\(", t[bs:be]):
        a = bs + m.end() - 1
        b = match_close(t, a)
        if b > 0 and re.match(r"\s*\{", t[b + 1:]) and not re.search(r"\bdo\s*\{[^}]*\}\s*$", t[:bs + m.start()]):
            yield f"while2for@{a}", t[:bs + m.start()] + f"for (; {t[a + 1:b].strip()}; )" + t[b + 1:]


def sub_forms(c):
    """The forms of a comparison of two values through a subtraction: `a == b`, `!(a - b)`, `(a - b) == 0`."""
    s = c.strip()
    if s.startswith("!"):
        inner = strip_parens(s[1:].strip())
        parts = split_top(inner, " - ") if inner is not None else []
        if len(parts) == 2:
            yield "unsub", f"{inner[:parts[0][1]].strip()} == {inner[parts[1][0]:parts[1][1]].strip()}"
        return
    cmp = find_cmp(s)
    if not cmp or cmp[1] not in ("==", "!=") or top_positions(s, "&|?"):
        return
    left, op, right = cmp
    if right == "0":
        li = strip_parens(left) or left
        parts = split_top(li, " - ")
        if len(parts) == 2:
            yield "unsub0", f"{li[:parts[0][1]].strip()} {op} {li[parts[1][0]:parts[1][1]].strip()}"
    else:
        yield "sub", f"!({left} - {right})" if op == "==" else f"({left} - {right})"
        yield "sub0", f"({left} - {right}) {op} 0"


def m_subcmp(t, name):
    """`a == b` <-> `!(a - b)` <-> `(a - b) == 0`, and `a != b` <-> `(a - b)`: the ROM subtracts, then branches on the difference."""
    loc = locate(t, name)
    if not loc:
        return
    for label, cs, ce in expr_sites(t, loc[2], loc[3]):
        if label in ("if", "while", "for", "return"):
            for tag, new in sub_forms(t[cs:ce]):
                yield f"{tag}@{cs}", t[:cs] + new + t[ce:]


def m_cc(t, name):
    """Per file: the compiler (`// COMPILER: ido53` added or removed) together with the optimisation, `-g` and `-mips2` choices."""
    lines = t.split("\n")
    head = [l for l in lines[:3] if l.startswith(("// FLAGS:", "// COMPILER:"))]
    body = "\n".join(lines[len(head):])
    flags = next((l[len("// FLAGS:"):].split() for l in head if l.startswith("// FLAGS:")), ["-O2", "-g3", "-mips2"])
    old53 = any(l.startswith("// COMPILER: ido53") for l in head)
    base = [f for f in flags if f not in ("-O1", "-O2", "-g", "-g0", "-g3", "-mips2")]
    toggled = [f for f in flags if f != "-mips2"] if "-mips2" in flags else flags + ["-mips2"]
    seen = set()
    for ido53 in (old53, not old53):
        for new in (toggled, ["-g"] + base, ["-g0"] + base, ["-g3"] + base, ["-O2", "-g3"] + base, ["-O2", "-g3", "-mips2"] + base, base):
            key = (ido53, tuple(new))
            if key in seen or (ido53 == old53 and new == flags):
                continue
            seen.add(key)
            text = (f"// FLAGS: {' '.join(new)}\n" if new else "") + ("// COMPILER: ido53\n" if ido53 else "") + body
            yield f"{'53' if ido53 else '71'}{' '.join(new)}", text


GRID_FAMILIES = ("-O0", "-O1", "-O2", "-O3", "-g", "-g0", "-g3", "-mips1", "-mips2", "-KPIC", "-non_shared", "-Wab,-r4300_mul", "-G", "0", "8")


def flag_grid(t):
    """(tag, new_text) for every combination of the compiler (IDO 7.1 / 5.3), -O0..-O3, -g/-g0/-g3, -mips1/-mips2, -G 0/8, -non_shared/-KPIC and
    -Wab,-r4300_mul that the draft does not use already (the flags that are not of these families stay): what an optimiser-level difference
    (an address hoisted into a register, a load merged or not) is made of."""
    lines = t.split("\n")
    head = [l for l in lines[:3] if l.startswith(("// FLAGS:", "// COMPILER:"))]
    body = "\n".join(lines[len(head):])
    flags = next((l[len("// FLAGS:"):].split() for l in head if l.startswith("// FLAGS:")), ["-O2", "-g3", "-mips2"])
    old53 = any(l.startswith("// COMPILER: ido53") for l in head)
    base = [f for f in flags if f not in GRID_FAMILIES]
    cur = (old53, tuple(sorted(f for f in flags if f in GRID_FAMILIES)))
    for ido53 in (False, True):
        for o in ("-O0", "-O1", "-O2", "-O3"):
            for g in ("-g", "-g0", "-g3"):
                for mips in ("-mips1", "-mips2"):
                    for gp in ((), ("-G", "8")):
                        for pic in ("-non_shared", "-KPIC"):
                            for mul in ((), ("-Wab,-r4300_mul",)):
                                new = [o, g, mips, *gp, *mul, *([] if pic == "-non_shared" else [pic])] + base
                                if (ido53, tuple(sorted(f for f in new if f in GRID_FAMILIES))) == cur:
                                    continue
                                text = f"// FLAGS: {' '.join(new)}\n" + ("// COMPILER: ido53\n" if ido53 else "") + body
                                yield f"{'53' if ido53 else '71'} {' '.join(new[:len(new) - len(base)])}", text



def add_typedef(t, line):
    """`line` (a typedef) after the last #include of the text, unless it is already there."""
    if line in t:
        return t
    inc = list(re.finditer(r"^#include [^\n]*\n", t, re.M))
    pos = inc[-1].end() if inc else 0
    return t[:pos] + line + "\n" + t[pos:]


def m_stride(t, name):
    """`M2C_FIELD((p + (i * 0x44)), s32 *, 0x17D98)`: an element of an array of structures whose size is not that of the field. It becomes
    `((Elem *)(p + 0x17D98))[i].w` with `typedef struct { s32 w; u8 pad[0x40]; } Elem;`: IDO then adds the base and the scaled index in the
    order of the ROM (`addu t0, s1, t8` against `addu t0, t8, s1`)."""
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    size = {"s8": 1, "u8": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "f32": 4}
    for m in re.finditer(r"M2C_FIELD\(", t[bs:be]):
        a = bs + m.end() - 1
        b = match_close(t, a)
        if b < 0:
            continue
        inner = t[a + 1:b]
        cuts = split_top(inner, ",")
        if len(cuts) != 3:
            continue
        base, ty, off = (inner[s:e].strip() for s, e in cuts)
        tm = re.fullmatch(r"(s8|u8|s16|u16|s32|u32|f32) \*", ty)
        bb = strip_parens(base) or base
        parts = split_top(bb, " + ")
        if not tm or len(parts) != 2:
            continue
        sides = [(bb[s:e].strip()) for s, e in parts]
        for k in (0, 1):
            p0, term = sides[k], strip_parens(sides[1 - k]) or sides[1 - k]
            mul = split_top(term, " * ")
            if len(mul) != 2:
                continue
            x, y = (term[s:e].strip() for s, e in mul)
            idx, n = (x, y) if y.lower().startswith(("0x",)) or y.isdigit() else (y, x)
            if not (n.lower().startswith("0x") or n.isdigit()) or int(n, 0) <= size[tm.group(1)]:
                continue
            n = int(n, 0)
            if n == size[tm.group(1)]:
                continue
            elem = f"Stride{n:X}_{tm.group(1)}"
            td = f"typedef struct {{ {tm.group(1)} w; u8 pad[0x{n - size[tm.group(1)]:X}]; }} {elem};"
            new = t[:bs + m.start()] + f"(({elem} *)({p0} + {off}))[{idx}].w" + t[b + 1:]
            yield f"@{a}", add_typedef(new, td)


def m_split(t, name):
    """The temporary the ROM keeps in another register: `x = E;` -> `T tmp = E; x = tmp;`, also with the first use of x that follows turned into tmp
    (`lw a0, ..; or s1, a0, zero` against `lw s1, ..; or a0, s1, zero`); `x = E + C;` with E the read of a field -> `tmp = E; x = tmp + C;`."""
    loc = locate(t, name)
    if not loc:
        return
    bs, be = loc[2], loc[3]
    sts = statements(t, bs, be)
    declared = {m.group("name") for a, b, k in sts if k == "decl" for m in [DECL.match(t[a:b])] if m}
    first_stmt = next((s for s in sts if s[2] != "decl"), None)
    if not first_stmt:
        return
    for n, (a, b, k) in enumerate(sts):
        if k != "stmt":
            continue
        m = re.fullmatch(r"(?P<v>[A-Za-z_]\w*) = (?P<e>M2C_FIELD\([^;]*\)|[A-Za-z_]\w*\[[^;]*\])(?P<op> [-+] [^;]+)?;", t[a:b], re.S)
        if not m or m.group("v") not in declared:
            continue
        v, e, op = m.group("v"), m.group("e"), m.group("op") or ""
        ty = "s32"
        fm = re.match(r"M2C_FIELD\(.*, ([\w ]+ \**)\*, [^,]+\)$", e, re.S)
        if fm:
            ty = fm.group(1).strip() if not fm.group(1).startswith("M2C_UNK") else "s32"
        tmp = f"{v}_t"
        decl = f"{ty}{'' if ty.endswith('*') else ' '}{tmp};\n{indent_of(t, first_stmt[0])}"
        stmt_new = f"{tmp} = {e};\n{indent_of(t, a)}{v} = {tmp}{op};"
        base = t[:a] + stmt_new + t[b:]
        yield f"{v}@{a}", base[:first_stmt[0]] + decl + base[first_stmt[0]:]
        if not op and n + 1 < len(sts):   # the first use of v in the following statement reads the temporary
            ns, ne = sts[n + 1][0], sts[n + 1][1]
            nxt = re.sub(r"\b" + v + r"\b", tmp, t[ns:ne], count=1)
            if nxt != t[ns:ne]:
                both = t[:a] + stmt_new + t[b:ns] + nxt + t[ne:]
                yield f"{v}@{a}+use", both[:first_stmt[0]] + decl + both[first_stmt[0]:]


MUTATORS = {
    "flags": m_flags, "cmp_swap": m_cmp_swap, "not_form": m_not_form, "cmp_const": m_cmp_const, "bool_swap": m_bool_swap,
    "if_swap": m_if_swap, "dup_return": m_dup_return, "drop_else": m_drop_else, "add_else": m_add_else, "stmt_swap": m_stmt_swap, "decl_swap": m_decl_swap,
    "pad": m_pad, "local_type": m_local_type, "param": m_param, "alias": m_alias, "inline_local": m_inline_local,
    "extract": m_extract, "late_local": m_late_local, "chain_assign": m_chain_assign, "commute": m_commute, "float_lit": m_float_lit, "cast": m_cast,
    "addu": m_addu, "ternary": m_ternary, "loop": m_loop, "callf32": m_callf32, "fieldsign": m_fieldsign, "index": m_index, "symarr": m_symarr, "retfold": m_retfold, "dropsp": m_dropsp, "fwdarg": m_fwdarg,
    "subcmp": m_subcmp, "cc": m_cc, "stride": m_stride, "split": m_split,
}


def variants(text, name, only=None):
    """[(mutator, site, new_text)] for every mutator (or those in `only`), one application each, without duplicates of the input."""
    out = []
    for mname, fn in MUTATORS.items():
        if only and mname not in only:
            continue
        try:
            for site, new in fn(text, name):
                if new != text:
                    out.append((mname, site, new))
        except (ValueError, IndexError, AttributeError, TypeError):
            continue   # a mutator that does not understand this source simply gives nothing
    return out
