#!/usr/bin/env python3
"""Rewrite an m2c draft (project form, `M2C_FIELD(p, T *, 0xOFF)` on `u8 *` variables) with one padded struct per pointer variable.
IDO then sees real member accesses: a large offset keeps its own `lui`/`addu` pair, a repeated base is not folded into a temporary the way
`(s8 *)p + off` is, and the registers follow the C the original had. A variable whose fields overlap or are read with two types at one
offset is left as it is.
usage: structify.py all ovlLO-ovlHI    rewrite the drafts of build/auto_drafts that score better structified (the old text goes to <fn>.c.orig)
       structify.py <draft.c>          prints the rewritten source
       structify.py <seg> <fn>         the draft of build/auto_drafts, rewritten and scored against the ROM (match server)"""
import re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SIZE = {"s8": 1, "u8": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "f32": 4, "f64": 8, "s64": 8, "u64": 8, "void *": 4}


def field_calls(t):
    """[(start, end, base, type_ptr, offset)] of the M2C_FIELD(base, type_ptr, offset) calls of t."""
    out, i = [], 0
    while True:
        i = t.find("M2C_FIELD(", i)
        if i < 0:
            return out
        j, depth, parts = i + 10, 1, []
        cur = j
        while depth:
            c = t[j]
            if c in "([":
                depth += 1
            elif c in ")]":
                depth -= 1
                if not depth:
                    parts.append(t[cur:j])
            elif c == "," and depth == 1:
                parts.append(t[cur:j])
                cur = j + 1
            j += 1
        if len(parts) == 3:
            out.append((i, j, parts[0].strip(), parts[1].strip(), parts[2].strip()))
        i = j


def field_type(tp):
    """Type of the member read through a pointer type `T *`: pointers become void * (any pointer type takes them)."""
    tp = re.sub(r"\s+", " ", tp)
    if not tp.endswith("*"):
        return None
    inner = tp[:-1].strip()
    if inner.endswith("*"):
        return "void *"
    return inner if inner in SIZE else None


def structify(text):
    m = re.search(r"^[^\n#]*\b(func_\w+)\(([^)]*)\)\s*\{", text, re.M)
    if not m:
        return text
    head_end = m.end()
    params = m.group(2)
    names = set(re.findall(r"\bu8 \*(\w+)", params))
    body_start = head_end
    for d in re.finditer(r"^\s+u8 \*(\w+);", text[head_end:], re.M):
        names.add(d.group(1))
    calls = [c for c in field_calls(text) if c[0] > head_end and c[2] in names]
    plan = {}
    for _, _, base, tp, off in calls:
        ft = field_type(tp)
        try:
            o = int(off, 0)
        except ValueError:
            ft = None
        if ft is None:
            plan[base] = None
            continue
        if base in plan and plan[base] is None:
            continue
        flds = plan.setdefault(base, {})
        if o in flds and flds[o] != ft:
            plan[base] = None
        else:
            flds[o] = ft
    structs, ok = [], {}
    for base, flds in plan.items():
        if not flds:
            continue
        pos, parts, good = 0, [], True
        for o in sorted(flds):
            if o < pos:
                good = False
                break
            if o > pos:
                parts.append(f"u8 pad{pos:X}[0x{o - pos:X}];")
            parts.append(f"{flds[o]} unk{o:X};".replace("* ", "*"))
            pos = o + SIZE[flds[o]]
        if good:
            ok[base] = flds
            structs.append(f"typedef struct {{ {' '.join(parts)} }} S_{base};")
    if not ok:
        return text
    # rewrite from the end so offsets stay valid
    for s, e, base, tp, off in sorted(calls, reverse=True):
        if base in ok:
            text = text[:s] + f"{base}->unk{int(off, 0):X}" + text[e:]
    for base in ok:
        text = re.sub(rf"\bu8 \*{base}\b", f"S_{base} *{base}", text)
        text = re.sub(rf"(?<![\w>.]){base} \+ ", f"(u8 *){base} + ", text)
        text = re.sub(rf"(?<![\w>.]){base} - ", f"(u8 *){base} - ", text)
    pre = text[:text.rfind("\n", 0, m.start() + 1) + 1] if m.start() else ""
    # structs go before the first declaration after the includes
    inc_end = max((x.end() for x in re.finditer(r'^#include .*\n', text, re.M)), default=0)
    return text[:inc_end] + "\n" + "\n".join(structs) + "\n" + text[inc_end:]


def normalize(text):
    """What makes an m2c draft compile: the sized unknown types, and prototypes without floats declared without parameters (a function m2c
    sees called with different argument counts is a compile error otherwise)."""
    text = re.sub(r"\bM2C_UNK(8|16|32|64)\b", r"s\1", text)

    def proto(m):
        return m.group(0) if re.search(r"\bf(32|64)\b", m.group(2)) else f"{m.group(1)}();"
    return re.sub(r"^([A-Za-z_][\w ]*?[\s*]+func_\w+)\(([^)]*)\);(?=\s*/\* extern \*/)", proto, text, flags=re.M)


def score(r):
    return r["score"] if r.get("status") in ("MATCH", "DIFF", "SIZE") else 1e9


def run_all(spec):
    sys.path[:0] = [str(ROOT / "tools/fast")]
    import client
    from concurrent.futures import ThreadPoolExecutor
    lo, hi = (int(x) for x in re.fullmatch(r"(?:ovl)?(\d{4})-(?:ovl)?(\d{4})", spec).groups())
    todo = [p for d in sorted((ROOT / "build/auto_drafts").glob("ovl*")) if lo <= int(d.name[3:]) <= hi for p in sorted(d.glob("*.c"))
            ]

    def one(p):
        seg, fn = p.parent.name, p.stem
        old = p.read_text().replace("m2c_macros", "m2c_compat")
        norm = normalize(old)
        cands = [c for c in (norm, structify(norm)) if c != old]
        if not cands:
            return 0
        a = client.match(seg, fn, source=old)
        best = min(((score(client.match(seg, fn, source=c)), i, c) for i, c in enumerate(cands)), key=lambda x: x[:2])
        new, b = best[2], {"score": best[0], "status": "DIFF"}
        if score(b) < score(a):
            p.with_suffix(".c.orig").write_text(old)
            p.write_text(new)
            return 1
        return 0
    with ThreadPoolExecutor(3) as ex:
        n = sum(ex.map(one, todo))
    print(f"{n} of {len(todo)} drafts improved")


if __name__ == "__main__":
    if sys.argv[1] == "all":
        run_all(sys.argv[2])
    elif len(sys.argv) == 2:
        print(structify(Path(sys.argv[1]).read_text().replace("\r", "")))
    else:
        sys.path[:0] = [str(ROOT / "tools/fast")]
        import client
        seg, fn = sys.argv[1:3]
        src = (ROOT / "build/auto_drafts" / seg / f"{fn}.c").read_text().replace("m2c_macros", "m2c_compat")
        new = structify(src)
        print(new)
        r = client.match(seg, fn, source=new)
        print(r.get("status"), r.get("score"), r.get("error", ""))
