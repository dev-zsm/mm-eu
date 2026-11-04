#!/usr/bin/env python3
"""Quick checks of the tools themselves (a few seconds, no ROM and no compiler needed). usage: selftest.py
  1. every script parses
  2. the project root computed from the location of each script is the real one (a moved script breaks this first)
  3. every shell script parses
  4. the pure functions of the tools give the expected answers on small inputs
Run by `make selftest`, at the start of tools/run/daily.sh and by the workflow of GitHub."""
import ast, re, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TOOLS = ROOT / "tools"
sys.path[:0] = [str(d) for d in TOOLS.glob("*/") if d.name != "vendor"]
failures = []


def check(ok, what):
    if not ok:
        failures.append(what)
        print("FAIL", what)


# 1 and 2: static checks of every script
for p in sorted(TOOLS.glob("*/*.py")):
    rel = p.relative_to(ROOT)
    try:
        ast.parse(p.read_text())
    except SyntaxError as e:
        check(False, f"{rel}: {e}")
        continue
    control = {chr(i) for i in (*range(0, 9), 11, 12, *range(14, 32))}   # a backslash lost on the way becomes one of these (\b, \1 ...)
    check(not control & set(p.read_text()), f"{rel}: control character in the source (a lost backslash)")
    m = re.search(r"ROOT = Path\(__file__\)\.resolve\(\)\.parents\[(\d)\]", p.read_text())
    if m:
        check(p.parents[int(m.group(1))] == ROOT, f"{rel}: parents[{m.group(1)}] is not the project root")

# 3: shell scripts
for p in sorted(TOOLS.glob("*/*.sh")) + [TOOLS / "mm"]:
    r = subprocess.run(["bash", "-n", str(p)], capture_output=True, text=True)
    check(r.returncode == 0, f"{p.relative_to(ROOT)}: {r.stderr.strip()[:80]}")

# 4: the pure functions
import names  # noqa: E402
check(names.apply("jal func_80001234; x_func_80001234", {"func_80001234": "Foo"}) == "jal Foo; x_func_80001234", "names.apply whole words")

import retype  # noqa: E402
new, why = retype.rewrite("#include \"types.h\"\nvoid func_80000000(s32 a0) {\n    a0 + 4;\n}\n", "func_80000000", "actor.h",
                          "void func_80000000(Actor *thisx);")
check(new is not None and "(u8 *)thisx + 4" in new and '#include "actor.h"' in new, f"retype.rewrite: {why}")
check(retype.rewrite("void f(s32 a, s32 b) {\n}\n", "f", "x.h", "void f(s32 a);")[0] is None, "retype refuses fewer parameters")
once = retype.rewrite("void f(s32 a) {\n    a + 4;\n}\n", "f", "x.h", "void f(void *p);")[0]
check(retype.rewrite(once, "f", "x.h", "void f(void *p);")[0].count("(u8 *)") == 1, "retype is idempotent on casts")

import sig_header  # noqa: E402
check(sig_header.type_known("void", "s32 a, f32 *b") and not sig_header.type_known("void", "PlayState *play"), "sig_header.type_known")

import ref_import  # noqa: E402
chunks = ref_import.top_chunks("#include \"a.h\"\n// c\nstatic s32 sX[] = { 1, 2 };\nvoid F(s32 a) {\n    if (a) { return; }\n}\ntypedef struct { s32 x; } T;\n")
check([c[0] for c in chunks] == ["pp", "decl", "func", "decl"], f"ref_import.top_chunks {[c[0] for c in chunks]}")
check(ref_import.as_extern("static s32 sX[] = { 1, 2 }") == "extern s32 sX[]", "ref_import.as_extern drops the initialiser")
check(ref_import.func_name(chunks[2][1]) == "F", "ref_import.func_name")

func = "void F(void) {\n    func_80001234();\n}"
h = ref_import.build_header("x", [("pp", '#include "a.h"'), ("decl", "static s32 sA[] = { 1 }"), ("func", func)], {"sA": "D_80000000"})
check(h.index("#define sA D_80000000") < h.index('#include "a.h"') and "extern s32 sA[];" in h and "void F(void);" in h, "ref_import.build_header")
check("ref_func_80001234" in ref_import.function_file("x", [("func", func)], "F"), "ref_import prefixes the reference's address names")

import srcpath  # noqa: E402
check(srcpath.path("overlays", "func_80000000").name == "func_80000000.c", "srcpath.path")

print(f"{len(failures)} failure(s)" if failures else "selftest: OK")
sys.exit(1 if failures else 0)
