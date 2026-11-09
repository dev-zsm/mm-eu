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
    for extra in ("-trapuv",):
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
        if not simple and uses != 1:
            continue
        sub = rhs if simple else f"({rhs})"
        rest = re.sub(r"\b" + var + r"\b", lambda _: sub, t[b:be]) + t[be:]
        ls = line_start(t, a)
        new = (t[:ls] + rest.lstrip(" ").lstrip("\n")) if t[ls:a].strip() == "" else t[:a] + rest
        for da, db, _ in bare:   # the declaration without initialiser goes too
            if db < a and new[line_start(new, da):da].strip() == "":
                new = new[:line_start(new, da)] + new[db:].lstrip(" ").lstrip("\n")
        yield var, new


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


MUTATORS = {
    "flags": m_flags, "cmp_swap": m_cmp_swap, "not_form": m_not_form, "cmp_const": m_cmp_const, "bool_swap": m_bool_swap,
    "if_swap": m_if_swap, "dup_return": m_dup_return, "drop_else": m_drop_else, "add_else": m_add_else, "stmt_swap": m_stmt_swap, "decl_swap": m_decl_swap,
    "pad": m_pad, "local_type": m_local_type, "param": m_param, "alias": m_alias, "inline_local": m_inline_local,
    "extract": m_extract, "chain_assign": m_chain_assign, "commute": m_commute, "float_lit": m_float_lit, "cast": m_cast,
    "addu": m_addu, "ternary": m_ternary, "loop": m_loop,
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
