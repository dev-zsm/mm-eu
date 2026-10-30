#!/usr/bin/env python3
"""Candidate names from a reference symbol table (zeldaret/mm function lists), found by aligning function-size
sequences with ours. A candidate is applied to
config/<seg>.names.txt only through this strict filter (`--write`), tagged `ref:`.
usage: ref_align.py <seg> <ref functions.txt> [--write]
Strict filter: the function lies in a run of >= 20 consecutive functions with identical sizes, at least 2 functions
away from the run's ends, its window of +-2 neighbour sizes is unique in our whole segment, and the reference name
is a real name (not func_XXXXXXXX). Candidates for every run >= 8 go to build/ref/candidates_<seg>.txt."""
import collections, difflib, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
RANGE = {"boot": (0x80080000, 0x800A5000), "code": (0x800A5000, 0x80200000)}
MIN_RUN, WIN = 20, 2


def ref_funcs(path, lo, hi):
    fs = []
    for l in Path(path).read_text().splitlines():
        m = re.match(r"(\w+) = (0x[0-9A-Fa-f]+); // type:func", l)
        if m and lo <= int(m.group(2), 16) < hi:
            fs.append((int(m.group(2), 16), m.group(1)))
    return sorted(fs)


def our_funcs(seg):
    t = (ROOT / "asm" / seg / "text.s").read_text()
    return sorted((int(m.group(1)[-8:], 16), m.group(1)) for m in re.finditer(r"^nonmatching (func_[0-9A-F]{8})", t, re.M))


def align(seg, refpath):
    """[(our name, ref name, run length, strict?)] for every function in a run of >= 8 equal sizes."""
    o, r = our_funcs(seg), ref_funcs(refpath, *RANGE[seg])
    sz = lambda fs: [fs[i + 1][0] - fs[i][0] for i in range(len(fs) - 1)]
    a, b = sz(o), sz(r)
    seen = collections.Counter(tuple(a[max(0, i - WIN):i + WIN + 1]) for i in range(len(a)))
    out = []
    for bl in difflib.SequenceMatcher(None, a, b, autojunk=False).get_matching_blocks():
        if bl.size < 8:
            continue
        for k in range(bl.size):
            i, j = bl.a + k, bl.b + k
            strict = (bl.size >= MIN_RUN and WIN <= k < bl.size - WIN and seen[tuple(a[max(0, i - WIN):i + WIN + 1])] == 1
                      and not re.fullmatch(r"(func|D)_[0-9A-F]{8}", r[j][1]))
            out.append((o[i][1], r[j][1], bl.size, strict))
    return out


def main():
    seg, refpath = sys.argv[1], sys.argv[2]
    cand = align(seg, refpath)
    with (ROOT / "build/ref" / f"candidates_{seg}.txt").open("w") as f:
        for o, r, n, s in cand:
            f.write(f"{o} {r} {n} {'strict' if s else 'weak'}\n")
    strict = [c for c in cand if c[3]]
    dup = {n for n, c in collections.Counter(c[1] for c in strict).items() if c > 1}
    strict = [c for c in strict if c[1] not in dup]  # a name given twice is a misalignment: drop both
    print(f"{seg}: {len(cand)} candidates (runs >= 8), {len(strict)} strict, {len(dup)} duplicate names dropped")
    if "--write" in sys.argv:
        path = ROOT / "config" / f"{seg}.names.txt"
        have = {l.split("#")[0].split()[0] for l in path.read_text().splitlines() if l.split("#")[0].split()} if path.exists() else set()
        used = {l.split("#")[0].split()[1] for l in path.read_text().splitlines() if len(l.split("#")[0].split()) > 1} if path.exists() else set()
        with path.open("a") as f:
            for o, r, n, _ in strict:
                if o not in have and r not in used:
                    f.write(f"{o} {r}   # ref: same-size run of {n} functions with the reference table (zeldaret US), unique neighbour sizes\n")
        print(f"names written to {path}")


if __name__ == "__main__":
    main()
