#!/usr/bin/env python3
"""Symbol renaming layer. config/<seg>.names.txt maps the splat names (func_8008XXXX, D_8009XXXX) to real names:
    func_80087634 free        # sdk: heap free (libc)
    func_80080150 osInvalDCache2   # inferred: ...
Columns: old new, then a comment starting with `sdk:` (official SDK/game name, high confidence) or
`inferred:` (project name chosen from what the code does). Files and addresses keep the old names; only symbols change."""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def load(seg: str) -> dict:
    path = ROOT / "config" / f"{seg}.names.txt"
    out = {}
    if path.exists():
        for line in path.read_text().splitlines():
            line = line.split("#", 1)[0].split()
            if len(line) >= 2:
                out[line[0]] = line[1]
    return out


def apply(text: str, names: dict) -> str:
    """Replace whole-word occurrences of old symbols by their new names."""
    if not names:
        return text
    pat = re.compile(r"\b(?:" + "|".join(map(re.escape, sorted(names, key=len, reverse=True))) + r")\b")
    return pat.sub(lambda m: names[m.group(0)], text)


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




def apply_sources(seg: str) -> int:
    """Rewrite src/<seg>/**/*.c so they use the real names (idempotent). Returns the number of files changed."""
    names = load(seg)
    n = 0
    for f in (ROOT / "src" / seg).rglob("*.c"):
        old = f.read_text()
        new = apply(old, names)
        if new != old:
            f.write_text(new)
            n += 1
    return n


if __name__ == "__main__":
    import sys
    print(f"{sys.argv[1]}: {check(sys.argv[1])} names OK")
    if "--apply-src" in sys.argv:
        print(f"{apply_sources(sys.argv[1])} source files updated")
