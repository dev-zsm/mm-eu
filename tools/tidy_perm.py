#!/usr/bin/env python3
"""Turn the raw output of the permuter (build/perm_wins/<fn>.c) into project-style C, checking the match after every step.
Run in WSL.  usage: tidy_perm.py <seg> [--dry] [<fn> ...]      (no function: every file of build/perm_wins)
Steps, each kept only if tools/match.py still says MATCH: replace the block of typedefs by `#include "types.h"`,
K&R braces, 4-space indentation, a one-line comment above stores that must share a source line, then removal of
the usual permuter leftovers (`(long)`, `& 0xFFFFFFFFu`, `x += 0;`).
A file that is tidy enough is written to src/<seg>/<fn>.c and its wip draft is deleted; otherwise it stays in
build/perm_wins/ and is reported. --dry writes to build/perm_tidy/<fn>.c instead and touches nothing else.
Names are not touched: naming is a separate pass."""
import re, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
WINS = ROOT / "build" / "perm_wins"
TYPEDEF = re.compile(r"^typedef (?:signed char|unsigned char|signed short|unsigned short|signed int|unsigned int|"
                     r"signed long long|unsigned long long|float|double|s32) (?:s8|u8|s16|u16|s32|u32|s64|u64|f32|f64|M2C_UNK);$")
ONE_LINE = "// one line: the ROM's scheduling depends on these stores sharing a single source line"


def matches(seg: str, fn: str, text: str) -> bool:
    tmp = WINS / f".tidy_{fn}.c"
    tmp.write_text(text)
    try:
        r = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), seg, fn, str(tmp)], capture_output=True, text=True)
    finally:
        tmp.unlink()
    return "MATCH" in r.stdout and "differ" not in r.stdout


def drop_typedefs(t: str) -> str:
    lines = [l for l in t.split("\n") if not TYPEDEF.match(l.strip())]
    if any(l.startswith('#include "types.h"') for l in lines):
        return "\n".join(lines)
    head = 0
    while head < len(lines) and lines[head].startswith("//"):
        head += 1  # keep the `// FLAGS:` and `// COMPILER:` lines first
    rest = "\n".join(lines[head:]).lstrip("\n")
    return "\n".join(lines[:head] + ['#include "types.h"', "", rest])


def braces(t: str) -> str:
    t = re.sub(r"[ \t]*\n[ \t]*\{[ \t]*\n", " {\n", t)
    t = re.sub(r"\}\s*\n\s*(while \([^)]*\);)", r"} \1", t)
    return re.sub(r"\}\s*\n\s*else\b", "} else", t)


def reindent(t: str) -> str:
    out, prev = [], 0
    for line in t.split("\n"):
        if not line.strip():
            out.append("")
            continue
        n = len(line) - len(line.lstrip(" "))
        if n == 1:  # the permuter leaves a one-space indent on lines it rewrote: follow the previous line
            indent = prev + (4 if out and out[-1].rstrip().endswith("{") else 0)
        else:
            indent = n * 2
        out.append(" " * indent + line.strip())
        prev = indent
    return "\n".join(out)


def comment_one_line(t: str) -> str:
    out = []
    for line in t.split("\n"):
        s = line.strip()
        if s.count("->") >= 2 and s.count(";") >= 2 and not s.startswith(("for", "typedef", "//")) and \
                not (out and out[-1].strip().startswith("// one line")):
            out.append(line[:len(line) - len(line.lstrip())] + ONE_LINE)
        out.append(line)
    return "\n".join(out)


def tidy_text(seg: str, fn: str, raw: str):
    cur, notes = raw, []
    for step in (drop_typedefs, braces, reindent, comment_one_line):
        new = step(cur)
        if new != cur:
            if matches(seg, fn, new):
                cur = new
            else:
                notes.append(f"{step.__name__} breaks the match")
    for pat, rep in ((r"\(long\)\s*", ""), (r"\s*&\s*0xFFFFFFFFu?\b", ""), (r"\n[ \t]*\w+\s*\+=\s*0;", "")):
        new = re.sub(pat, rep, cur)
        if new != cur and matches(seg, fn, new):
            cur = new
    cur = "\n".join(l.rstrip() for l in cur.split("\n")).strip("\n") + "\n"
    if matches(seg, fn, cur):
        return cur, notes
    return raw, notes + ["final whitespace cleanup breaks the match"]


def tidy_enough(t: str) -> bool:
    return 'typedef signed char s8;' not in t and not re.search(r"^\s*\{\s*$", t, re.M)


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    dry = "--dry" in sys.argv
    seg, fns = args[0], args[1:] or sorted(p.stem for p in WINS.glob("func_*.c"))
    for fn in fns:
        raw = (WINS / f"{fn}.c").read_text().replace("\r", "")
        if not matches(seg, fn, raw):
            print(f"{fn}: the raw file does not match any more, skipped")
            continue
        new, notes = tidy_text(seg, fn, raw)
        if not tidy_enough(new):
            print(f"{fn}: left in build/perm_wins/ ({'; '.join(notes) or 'not tidy enough'})")
            continue
        dst = ROOT / "build" / "perm_tidy" / f"{fn}.c" if dry else ROOT / "src" / seg / f"{fn}.c"
        dst.parent.mkdir(parents=True, exist_ok=True)
        dst.write_text(new)
        if not dry:
            (ROOT / "src" / seg / "wip" / f"{fn}.c").unlink(missing_ok=True)
            (WINS / f"{fn}.c").unlink()
        print(f"{fn}: tidied -> {dst.relative_to(ROOT)}" + (f" ({'; '.join(notes)})" if notes else ""))


if __name__ == "__main__":
    main()
