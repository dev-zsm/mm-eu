#!/usr/bin/env python3
"""Symbol renaming layer. config/<seg>/names.txt maps the splat names (func_8008XXXX, D_8009XXXX) to real names:
    func_80087634 free        # sdk: heap free (libc)
    func_80080150 osInvalDCache2   # inferred: ...
Columns: old new, then a comment starting with `sdk:` (official SDK/game name, high confidence),
`ref:` (name taken from the reference decompilation credited in the README, found by tools/research/ref_align.py and
spot-checked against our verified C) or `inferred:` (project name chosen from what the
code does). Files and addresses keep the old names; only symbols change."""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def load(seg: str) -> dict:
    """{old: new} of a segment. An overlay (`ovlNNNN`) reads its own lines of config/overlays/names.txt (`NNNN old new`)."""
    ovl = re.fullmatch(r"ovl(\d{4})", seg)
    path = ROOT / "config" / ("overlays" if ovl else seg) / "names.txt"
    out = {}
    if path.exists():
        for line in path.read_text().splitlines():
            line = line.split("#", 1)[0].split()
            if ovl:
                if len(line) == 3 and line[0] == ovl.group(1):
                    out[line[1]] = line[2]
            elif len(line) >= 2:
                out[line[0]] = line[1]
    return out


def apply(text: str, names: dict) -> str:
    """Replace whole-word occurrences of old symbols by their new names."""
    if not names:
        return text
    pat = re.compile(r"\b(?:" + "|".join(map(re.escape, sorted(names, key=len, reverse=True))) + r")\b")
    return pat.sub(lambda m: names[m.group(0)], text)


# the lines of a context header (include/generated/mm/) that keep the reference's own address names out of the way while its headers are read:
# `#define func_800B8E1C ref_func_800B8E1C` ... `#undef func_800B8E1C`. They name what the reference spells, not what we call it.
PREFIX_LINE = re.compile(r"^#(?:define \w+ ref_\w+|undef \w+)[ \t]*$", re.M)


def apply_keeping_prefixes(text: str, names: dict) -> str:
    """`apply`, except on the prefix lines of a context header: renamed, `#define Actor_X ref_func_800B8E1C` no longer prefixes the declaration
    of func_800B8E1C in the reference's header, which then clashes with our own prototype (En_Bubble, the round of 2026-11-12)."""
    kept = PREFIX_LINE.findall(text)
    for i, line in enumerate(kept):
        text = text.replace(line, f"@@KEEP{i}@@", 1)
    text = apply(text, names)
    for i, line in enumerate(kept):
        text = text.replace(f"@@KEEP{i}@@", line, 1)
    return text


def check(seg: str):
    """Names must be valid C identifiers, unique, and must not collide with a splat-generated name."""
    names = load(seg)
    seen = {}
    for old, new in names.items():
        assert re.fullmatch(r"[A-Za-z_]\w*", new), f"{old}: bad identifier {new!r}"
        assert not re.fullmatch(r"(func|D)_[0-9A-F]{8}", new), f"{old}: {new} looks like a splat name"
        assert new not in seen, f"{new} given to both {seen[new]} and {old}"
        seen[new] = old
    return len(names)




def _context_headers(sources):
    """File names of the generated/mm headers that the given sources include."""
    return sorted({m for p in sources for m in re.findall(r'#include "generated/mm/([^"]+)"', p.read_text())})


def apply_sources(seg: str) -> int:
    """Rewrite src/<seg>/**/*.c and the generated prototype header so they use the real names (idempotent). Returns the number of files changed."""
    names = load(seg)
    n = 0
    gen = ROOT / "include" / "generated"   # the prototypes and the aliases of the imported functions follow the names too
    if seg.startswith("ovl"):   # the overlay's folder, its prototypes, and the context headers of its reference file
        import srcpath
        sources = [p for p in srcpath.overlay_dir(seg[3:]).rglob("*.c")]
        hdrs = [gen / "overlays" / f"{seg[3:]}.h", *(gen / "mm" / h for h in _context_headers(sources))]
    else:
        sources = list((ROOT / "src" / seg).rglob("*.c"))
        hdrs = [gen / f"{seg}_funcs.h", *(gen / "mm").glob("*.h")] if seg == "code" else [gen / f"{seg}_funcs.h"]
    for f in [*sources, *[g for g in hdrs if g.exists()]]:
        old = f.read_text()
        new = apply_keeping_prefixes(old, names)
        if new != old:
            f.write_text(new)
            n += 1
    return n


def name_overlay_folders() -> int:
    """src/overlays/NNNN -> src/overlays/NNNN_<name> for the overlays config/overlays/actors.txt names (idempotent)."""
    n = 0
    for line in (ROOT / "config" / "overlays" / "actors.txt").read_text().splitlines():
        parts = line.split("#", 1)[0].split()
        if len(parts) == 2:
            old = ROOT / "src" / "overlays" / parts[0]
            if old.is_dir() and not list(old.parent.glob(parts[0] + "_*")):
                old.rename(old.parent / f"{parts[0]}_{parts[1]}")
                n += 1
    return n


if __name__ == "__main__":
    import sys
    if sys.argv[1] == "overlays":   # every overlay: folders named, then the function names applied to the sources
        print(f"{name_overlay_folders()} folders named")
        for idx in sorted({l.split()[0] for l in (ROOT / "config" / "overlays" / "names.txt").read_text().splitlines() if l[:4].isdigit()}):
            check("ovl" + idx)
            if "--apply-src" in sys.argv:
                apply_sources("ovl" + idx)
        sys.exit()
    print(f"{sys.argv[1]}: {check(sys.argv[1])} names OK")
    if "--apply-src" in sys.argv:
        print(f"{apply_sources(sys.argv[1])} source files updated")
