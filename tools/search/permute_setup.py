#!/usr/bin/env python3
"""Prepare a decomp-permuter directory for one unmatched function. Run in WSL.
usage: permute_setup.py <seg> <fn>   ->  build/perm/<fn>/{base.c,target.o,compile.sh,settings.toml}
Needs the object of <fn> built by tools/lib/build_seg.py (kept in objcache.WORK): run `python3 tools/lib/build_seg.py <seg> ...` once first."""
import re, shutil, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import names  # noqa: E402
import objcache  # noqa: E402
import srcpath  # noqa: E402


def workdir(seg: str, fn: str) -> Path:
    """Overlays share function names (every one has a func_80000000): their work directory carries the overlay."""
    return ROOT / "build" / "perm" / (f"{seg}_{fn}" if seg.startswith("ovl") else fn)


def draft(seg: str, fn: str):
    """The unfinished C of a function: src/<seg>/wip, or for an overlay build/auto_drafts (made by tools/search/permute_list.py)."""
    if seg.startswith("ovl"):
        for p in (srcpath.overlay_dir(seg[3:]) / "wip" / f"{fn}.c", ROOT / "build" / "auto_drafts" / seg / f"{fn}.c"):
            if p.exists():
                return p
        return None
    p = ROOT / "src" / seg / "wip" / f"{fn}.c"
    return p if p.exists() else None


def overlay_target(seg: str, fn: str, out: Path):
    """target.o of an overlay function: its splat assembly, assembled."""
    import build_seg  # noqa: E402
    import match  # noqa: E402
    chunk = next(c for c in re.split(r"(?=^nonmatching )", match.asm_file(seg).read_text(), flags=re.M)[1:]
                 if c.startswith(f"nonmatching {fn},"))
    shutil.copyfile(objcache.assemble(build_seg.HDR + chunk, build_seg.AS), out)


def main():
    seg, fn = sys.argv[1:3]
    src = draft(seg, fn) or srcpath.path(seg, fn)
    text = src.read_text()
    m = re.match(r"// FLAGS: (.*)", text.splitlines()[0])
    flags = m.group(1) if m else "-O2 -g3 -mips2"
    d = workdir(seg, fn)
    d.mkdir(parents=True, exist_ok=True)
    cc, cc_env = (objcache.compiler_for(src), "MM_CC53" if objcache.uses_ido53(src) else "MM_CC")
    # the permuter wants one self-contained function: expand the includes with IDO's preprocessor,
    # which stops on an apostrophe in a `//` comment, so the comments go first
    plain = d / "plain.c"
    plain.write_text(re.sub(r"//.*", "", text))
    pre = subprocess.run([str(cc), "-E", "-Xcpluscomm", "-I" + str(ROOT / "include"), str(plain)],
                         capture_output=True, text=True, check=True).stdout
    base = re.sub(r"^# \d+.*\n", "", pre, flags=re.M)
    real = names.load(seg).get(fn)  # the C file defines the real name, but target.o carries the address name
    (d / "base.c").write_text(base.replace(real, fn) if real else base)
    if seg.startswith("ovl"):
        overlay_target(seg, fn, d / "target.o")
    else:
        shutil.copy(objcache.WORK / seg / "fn" / f"{fn}.o", d / "target.o")
    (d / "compile.sh").write_text(f"""#!/bin/bash
# usage: compile.sh input.c -o output.o  (IDO cc mishandles output paths with spaces: go through a temp file)
set -e
IN="$(realpath "$1")"; OUT="$(realpath -m "$3")"
T="$(mktemp -d)"; cp "$IN" "$T/x.c"
"${{{cc_env}:-{cc}}}" -c {flags} -G 0 -non_shared -Xcpluscomm -w -o "$T/x.o" "$T/x.c" 2>/dev/null
cp "$T/x.o" "$OUT"; rm -rf "$T"
""")
    (d / "compile.sh").chmod(0o755)
    # Pass weights suited to the differences that remain in the unfinished drafts (registers, instruction order, stack size):
    # more reordering of statements and declarations, type changes of variables and callees, frame padding, conditions.
    pass_weights = {"perm_temp_for_expr": 60, "perm_reorder_stmts": 30, "perm_reorder_decls": 30, "perm_pad_var_decl": 6,
             "perm_randomize_internal_type": 25, "perm_randomize_external_type": 15, "perm_randomize_function_type": 15,
             "perm_chain_assignment": 12, "perm_add_self_assignment": 10, "perm_commutative": 12, "perm_inequalities": 10,
             "perm_sameline": 20, "perm_empty_stmt": 15, "perm_condition": 20, "perm_split_assignment": 15}
    weights = "".join(f"{k} = {v}\n" for k, v in pass_weights.items())
    (d / "settings.toml").write_text(f'func_name = "{fn}"\ncompiler_type = "ido"\n\n[weight_overrides]\n{weights}')
    print(d)


if __name__ == "__main__":
    main()
