#!/usr/bin/env python3
"""Prepare a decomp-permuter directory for one unmatched function. Run in WSL.
usage: permute_setup.py <seg> <fn>   ->  build/perm/<fn>/{base.c,target.o,compile.sh,settings.toml}
Needs build/<seg>/fn/<fn>.o as the target: run `python3 tools/build_seg.py <seg> ...` once first."""
import re, shutil, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CC = ROOT / "tools/vendor/ido71/cc"


def main():
    seg, fn = sys.argv[1:3]
    src = ROOT / "src" / seg / "wip" / f"{fn}.c"
    if not src.exists():
        src = ROOT / "src" / seg / f"{fn}.c"
    text = src.read_text()
    m = re.match(r"// FLAGS: (.*)", text.splitlines()[0])
    flags = m.group(1) if m else "-O2 -g3 -mips2"
    d = ROOT / "build" / "perm" / fn
    d.mkdir(parents=True, exist_ok=True)
    # the permuter wants one self-contained function: expand the includes with IDO's preprocessor
    pre = subprocess.run([str(CC), "-E", "-Xcpluscomm", "-I" + str(ROOT / "include"), str(src)],
                         capture_output=True, text=True, check=True).stdout
    (d / "base.c").write_text(re.sub(r"^# \d+.*\n", "", pre, flags=re.M))
    shutil.copy(ROOT / "build" / seg / "fn" / f"{fn}.o", d / "target.o")
    (d / "compile.sh").write_text(f"""#!/bin/bash
# usage: compile.sh input.c -o output.o  (IDO cc mishandles output paths with spaces: go through a temp file)
set -e
IN="$(realpath "$1")"; OUT="$(realpath -m "$3")"
T="$(mktemp -d)"; cp "$IN" "$T/x.c"
"${{ZMM_CC:-{CC}}}" -c {flags} -G 0 -non_shared -Xcpluscomm -w -o "$T/x.o" "$T/x.c" 2>/dev/null
cp "$T/x.o" "$OUT"; rm -rf "$T"
""")
    (d / "compile.sh").chmod(0o755)
    (d / "settings.toml").write_text(f'func_name = "{fn}"\ncompiler_type = "ido"\n')
    print(d)


if __name__ == "__main__":
    main()
