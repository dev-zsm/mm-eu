#!/usr/bin/env python3
"""Write config/<seg>.layout.txt: the folder (original source file) of every function of the segment. Run in WSL.
usage: layout.py <seg>
The code segment is linked in source-file order, so each source file is a run of consecutive functions. A named function
belongs to the module of its registered name (prefix before the first '_'); an unnamed one to the module around it if
both named neighbours agree, else to a `<seg>_<address of its first function>` run, as for any file whose name is unknown.
The table is generated once and then kept (so renaming a function never moves its file); regenerate with --force."""
import re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import names


def module(name):
    """Module of a registered name: libultra (os*), libgu (gu*), libc (the other names without a `Module_` prefix), else the prefix."""
    bare = name.lstrip("_")
    if re.match(r"os[A-Z]", bare):
        return "libultra"
    if re.match(r"gu[A-Z]", bare):
        return "libgu"
    if "_" not in bare or name.startswith("__"):
        return "libc"
    return bare.split("_")[0]


def build(seg):  # folders of unknown name are `<seg>_<address of the first function>`
    nm = names.load(seg)
    fns = [m.group(1) for l in (ROOT / "asm" / seg / "text.s").read_text().splitlines()
           for m in [re.match(r"glabel (func_[0-9A-F]{8})$", l)] if m]
    pre = [module(nm[f]) if f in nm else None for f in fns]
    mod = list(pre)
    for i, m in enumerate(pre):
        if m is None:
            a = next((x for x in reversed(pre[:i]) if x), None)
            b = next((x for x in pre[i + 1:] if x), None)
            mod[i] = a if a == b else None
    out, run = [], None
    for f, m in zip(fns, mod):
        if m is None:
            run = run if run and run.startswith(seg + "_") else seg + "_" + f[5:]
        else:
            run = m
        out.append((f, run))
    return out


if __name__ == "__main__":
    seg = sys.argv[1]
    dst = ROOT / "config" / f"{seg}.layout.txt"
    if dst.exists() and "--force" not in sys.argv:
        sys.exit(f"{dst} exists; --force to regenerate (this moves files: run srcsort.py afterwards)")
    rows = build(seg)
    dst.write_text("".join(f"{f} {d}\n" for f, d in rows))
    print(f"{seg}: {len(rows)} functions in {len({d for _, d in rows})} folders -> {dst}")
