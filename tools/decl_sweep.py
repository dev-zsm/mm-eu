#!/usr/bin/env python3
"""Try every order of the plain local declarations of each unfinished draft (the order decides the stack layout and the
registers); promote any that matches. CPU only. Run in WSL.  usage: decl_sweep.py <seg> [max_locals=6]
Only `type name;` lines at the top of the function are moved (initialised ones stay). Log: build/decl_sweep_<seg>.txt"""
import itertools, re, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import match
import flag_sweep

DECL = re.compile(r"^\s+(?:register\s+)?(?:(?:const|volatile|unsigned|signed|struct)\s+)*[A-Za-z_]\w*[\s\*]+[\w\[\]\*0-9x]+;\s*$")


def split(body):
    """(head, decls, rest): the declarations right after the first `{` of the last function definition."""
    lines = body.split("\n")
    start = next((i for i in range(len(lines) - 1, -1, -1) if lines[i].rstrip().endswith("{") and "(" in lines[i]), None)
    if start is None:
        return None
    j = start + 1
    while j < len(lines) and DECL.match(lines[j]):
        j += 1
    return lines[:start + 1], lines[start + 1:j], lines[j:]


def main():
    seg, limit = sys.argv[1], int(sys.argv[2]) if len(sys.argv) > 2 else 6
    log = match.ROOT / "build" / f"decl_sweep_{seg}.txt"
    done = {l.split()[0] for l in log.read_text().splitlines()} if log.exists() else set()
    files = sorted((match.ROOT / "src" / seg / "wip").glob("func_*.c"))
    for f in files:
        fn = f.stem
        if fn in done:
            continue
        text = f.read_text()
        parts = split(text)
        if not parts or not 2 <= len(parts[1]) <= limit:
            continue
        head, decls, rest = parts
        want, _ = match.original(seg, fn)
        flags = match.file_flags(f)
        best, win = None, None
        tmp = f.with_name(f"{fn}.decl.c")
        for perm in itertools.permutations(decls):
            tmp.write_text("\n".join(head + list(perm) + rest))
            s = flag_sweep.score(tmp, fn, flags, want, len(want))
            if s is not None and (best is None or s < best):
                best = s
            if s == 0:
                win = list(perm)
                break
        tmp.unlink(missing_ok=True)
        if win:
            (match.ROOT / "src" / seg / f"{fn}.c").write_text("\n".join(head + win + rest))
            f.unlink()
        with log.open("a") as lf:
            lf.write(f"{fn} {'MATCHED' if win else 'no match'} best={best}\n")


if __name__ == "__main__":
    main()
