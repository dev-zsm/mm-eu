#!/usr/bin/env python3
"""Prepare a decomp-permuter directory for one unmatched function. Run in WSL.
usage: permute_setup.py <seg> <fn>   ->  build/perm/<fn>/{base.c,target.o,compile.sh,settings.toml}
Needs the object of <fn> built by tools/build_seg.py (kept in objcache.WORK): run `python3 tools/build_seg.py <seg> ...` once first."""
import re, shutil, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import names  # noqa: E402
import objcache  # noqa: E402
import srcpath  # noqa: E402

CC = objcache._compiler("71")


def main():
    seg, fn = sys.argv[1:3]
    src = ROOT / "src" / seg / "wip" / f"{fn}.c"
    if not src.exists():
        src = srcpath.path(seg, fn)
    text = src.read_text()
    m = re.match(r"// FLAGS: (.*)", text.splitlines()[0])
    flags = m.group(1) if m else "-O2 -g3 -mips2"
    d = ROOT / "build" / "perm" / fn
    d.mkdir(parents=True, exist_ok=True)
    # the permuter wants one self-contained function: expand the includes with IDO's preprocessor
    pre = subprocess.run([str(CC), "-E", "-Xcpluscomm", "-I" + str(ROOT / "include"), str(src)],
                         capture_output=True, text=True, check=True).stdout
    base = re.sub(r"^# \d+.*\n", "", pre, flags=re.M)
    real = names.load(seg).get(fn)  # the C file defines the real name, but target.o carries the address name
    (d / "base.c").write_text(base.replace(real, fn) if real else base)
    shutil.copy(objcache.WORK / seg / "fn" / f"{fn}.o", d / "target.o")
    (d / "compile.sh").write_text(f"""#!/bin/bash
# usage: compile.sh input.c -o output.o  (IDO cc mishandles output paths with spaces: go through a temp file)
set -e
IN="$(realpath "$1")"; OUT="$(realpath -m "$3")"
T="$(mktemp -d)"; cp "$IN" "$T/x.c"
"${{MM_CC:-{CC}}}" -c {flags} -G 0 -non_shared -Xcpluscomm -w -o "$T/x.o" "$T/x.c" 2>/dev/null
cp "$T/x.o" "$OUT"; rm -rf "$T"
""")
    (d / "compile.sh").chmod(0o755)
    # Boosted weights for the differences that remain in the unfinished drafts (registers, instruction order, stack size):
    # more reordering of statements and declarations, type changes of variables and callees, frame padding, conditions.
    boost = {"perm_temp_for_expr": 60, "perm_reorder_stmts": 30, "perm_reorder_decls": 30, "perm_pad_var_decl": 6,
             "perm_randomize_internal_type": 25, "perm_randomize_external_type": 15, "perm_randomize_function_type": 15,
             "perm_chain_assignment": 12, "perm_add_self_assignment": 10, "perm_commutative": 12, "perm_inequalities": 10,
             "perm_sameline": 20, "perm_empty_stmt": 15, "perm_condition": 20, "perm_split_assignment": 15}
    weights = "".join(f"{k} = {v}\n" for k, v in boost.items())
    (d / "settings.toml").write_text(f'func_name = "{fn}"\ncompiler_type = "ido"\n\n[weight_overrides]\n{weights}')
    print(d)


if __name__ == "__main__":
    main()
