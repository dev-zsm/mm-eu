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

# the workflow of GitHub runs pyflakes on the tools and fails on an unused import: so do the rounds, before they push
r = subprocess.run([sys.executable, "-m", "pyflakes", *map(str, sorted(TOOLS.glob("*/*.py")))], capture_output=True, text=True)
if "No module named pyflakes" not in r.stderr:
    for line in (r.stdout + r.stderr).splitlines():
        if "unable to detect undefined names" not in line:
            check(False, f"pyflakes: {line}")

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

ctx ="#define func_1 ref_func_1\n#define ref_func_1 func_2\n#undef func_1\nvoid func_1(void);\n"
check(names.apply_keeping_prefixes(ctx, {"func_1": "Real_One", "func_2": "Real_Two"})
      == "#define func_1 ref_func_1\n#define ref_func_1 Real_Two\n#undef func_1\nvoid Real_One(void);\n",
      "names.apply_keeping_prefixes leaves the prefix lines of a context header alone")

import sig_header  # noqa: E402
check(sig_header.type_known("void", "s32 a, f32 *b") and not sig_header.type_known("void", "PlayState *play"), "sig_header.type_known")

check(sig_header.type_known("void", "Actor *thisx, EnTest *this", sig_header.VOCAB | {"EnTest"}), "sig_header.type_known with the types of actor.h")
# the header of boot or code must not include actor.h: their files carry their own Vec3f and Actor typedefs (37 functions failed to compile)
check(not sig_header.vocab("code") and not sig_header.vocab("boot") and "Actor" in sig_header.vocab("ovl0050"), "sig_header.vocab: actor.h types only for an overlay")

import sig_ref  # noqa: E402
d = sig_ref.definitions("static s32 g(void) {\n}\nvoid EnX_Update(Actor* thisx,\n                PlayState* play) {\n    if (x) {\n    }\n}\n")
check(d == {"g": ("s32", "void"), "EnX_Update": ("void", "Actor* thisx, PlayState* play")}, f"sig_ref.definitions {d}")
check(sig_ref.proto("f", "bool", "EnX* this, Gfx** dl, u8* p, f32 s", {"EnX"}) == "s32 f(EnX *this, void *dl, u8 *p, f32 s)", "sig_ref.proto")
check(sig_ref.proto("f", "void", "ActorFlags x", set()) is None and sig_ref.proto("f", "void", "void (*cb)(void)", set()) is None, "sig_ref skips types it cannot say")
fl = sig_ref.flows([("addu", ["$s0", "$a0", "$zero"], 0), ("jal", ["f1"], 0x0C000004), ("addu", ["$a0", "$s0", "$zero"], 0),
                    ("jal", ["f2"], 0x0C000008), ("lw", ["$a0", "0x4($s0)"], 0)])
check(fl == [(0x80000010, {0: 0, 1: 1, 2: 2, 3: 3}), (0x80000020, {})], f"sig_ref.flows {fl}")
tr = sig_ref.trace([("or", ["$s0", "$a0", "$zero"], 0), ("sw", ["$a1", "0x2C($sp)"], 0), ("lui", ["$a1", "%hi(func_80000100)"], 0),
                    ("addiu", ["$a1", "$a1", "%lo(func_80000100)"], 0), ("sw", ["$a1", "0x18C($s0)"], 0), ("lw", ["$t9", "0x18C($s0)"], 0),
                    ("or", ["$a0", "$s0", "$zero"], 0), ("lw", ["$a1", "0x2C($sp)"], 0), ("jalr", ["$t9"], 0), ("nop", [], 0)])
check(tr[2] == [(0x18C, 0, ("f", 0x80000100))] and tr[1] == [(0x18C, 0, {0: ("p", 0), 1: ("p", 1), 2: ("p", 2), 3: ("p", 3)})], f"sig_ref.trace {tr}")

import ref_import  # noqa: E402
chunks = ref_import.top_chunks("#include \"a.h\"\n// c\nstatic s32 sX[] = { 1, 2 };\nvoid F(s32 a) {\n    if (a) { return; }\n}\ntypedef struct { s32 x; } T;\n")
check([c[0] for c in chunks] == ["pp", "decl", "func", "decl"], f"ref_import.top_chunks {[c[0] for c in chunks]}")
check(ref_import.as_extern("static s32 sX[] = { 1, 2 }") == "extern s32 sX[2]", "ref_import.as_extern drops the initialiser, keeps the size")
check([ref_import.initializer_count(s) for s in ("{ 1, F(2, 3), { 4, 5 }, \"a,b\", }", "{ }", "\"abc\"", "{ {1}, {2} };")] == [4, 0, 0, 2],
      "ref_import.initializer_count")
check(ref_import.func_name(chunks[2][1]) == "F", "ref_import.func_name")
ld_err = ("ld: warning: x\n/n/fn/func_8016C644.o: in function `func_8016C644':\n"
          "func_8016C644.c:(.text+0x10): warning\nfunc_8016C644.c:(.text+0x14): undefined reference to `gSaveContext'\n")
check([m.groups() for m in ref_import.UNDEF.finditer(ld_err)] == [("func_8016C644", "gSaveContext")], "ref_import.UNDEF names the object and the symbol of a failed link")
check(ref_import.CC_ERR.search("cfe: Error: src/code/Play/func_8016C644.c, line 9: 'x' undefined").group(1) == "src/code/Play/func_8016C644.c", "ref_import.CC_ERR")

func = "void F(void) {\n    func_80001234();\n}"
h = ref_import.build_header("x", [("pp", '#include "a.h"'), ("decl", "static s32 sA[] = { 1 }"), ("func", func)], {"sA": "D_80000000"})
check(h.index("#define sA D_80000000") < h.index('#include "a.h"') and "extern s32 sA[1];" in h and "void F(void);" in h, "ref_import.build_header")
check("ref_func_80001234" in ref_import.function_file("x", [("func", func)], "F"), "ref_import prefixes the reference's address names")

import close_mut  # noqa: E402
src = "void f(s32 a) {\n    s32 b;\n    s32 c;\n    if (a < 3) {\n        b = a;\n    } else {\n        b = 2;\n    }\n    c = 1;\n    b = 4;\n}\n"
vs = close_mut.variants(src, "f")
has = lambda m, frag: any(v[0] == m and frag in v[2] for v in vs)
check(has("cmp_swap", "if (3 > a)") and has("if_swap", "if (a >= 3)") and has("ternary", "b = a < 3 ? a : 2;"), "close_mut cmp_swap, if_swap, ternary")
check(has("stmt_swap", "b = 4;\n    c = 1;") and has("decl_swap", "s32 c;\n    s32 b;") and has("pad", "s32 pad;"), "close_mut stmt_swap, decl_swap, pad")
check(close_mut.negate("a < b") == "a >= b" and close_mut.negate("x") == "!x" and close_mut.negate("!x") == "x", "close_mut.negate")
check(all(v[2].count("{") == v[2].count("}") for v in vs), "close_mut keeps the braces balanced")
sv = close_mut.variants("// FLAGS: -O2 -g3 -mips2\nint f(int a, int b) {\n    if (a == b) {\n        return 1;\n    }\n    if ((a - b) != 0) {\n        return 2;\n    }\n    return 0;\n}\n", "f", only=["subcmp", "cc"])
check(any(v[0] == "subcmp" and "if (!(a - b))" in v[2] for v in sv) and any(v[0] == "subcmp" and "if (a != b)" in v[2] for v in sv)
      and any(v[0] == "cc" and v[2].startswith("// FLAGS: -O2 -g3 -mips2\n// COMPILER: ido53\n") for v in sv), "close_mut subcmp and cc")
check(sum(1 for _ in close_mut.flag_grid("int f(void) {\n}\n")) == 383, "close_mut.flag_grid: every combination but the draft's own")
iv = close_mut.variants("void f(u8 *arg0) {\n    s16 temp_a1;\n\n    temp_a1 = M2C_FIELD(arg0, s16 *, 0x16);\n    if (temp_a1 != 0) {\n        g(temp_a1);\n    }\n}\n", "f", only=["inline_local"])
check(len(iv) == 1 and iv[0][2].count("M2C_FIELD(arg0, s16 *, 0x16)") == 2 and "temp_a1" not in iv[0][2], "close_mut inline_local: a field read used twice is read again at each use")
import close  # noqa: E402
log = ["ovl0001 func_1 start 1.04 best 1.04  [v:aaaa1111]", "ovl0001 func_2 start 1.04 best 1.04  [v:bbbb2222]", "ovl0001 func_3 start 1.04 best 1.04",
       "ovl0001 func_4 start 1.04 MATCH  callf32:f#1  promote: True x.c"]
check(close.tried(log, "aaaa1111") == {("ovl0001", "func_1", "1.04")}, "close.tried keeps only the failures of the same mutators")

import srcpath  # noqa: E402
check(srcpath.path("overlays", "func_80000000").name == "func_80000000.c", "srcpath.path")

import score  # noqa: E402
sc = score.score([1, 2, 3, 4], [1, 2, 3, 4])
check(sc["diff"] == 0 and sc["score"] == 0, f"score.score identical {sc}")
sc = score.score([0x01, 0x02, 0x03, 0x04], [0x01, 0x03, 0x02, 0x04])
check(sc["diff"] == 2 and sc["moved"] == 2 and sc["hard"] == 0 and sc["first"] == [4, 8], f"score.score reordering {sc}")
sc = score.score([0x8C850000, 0x00A62021], [0x8CA40000, 0x00A62021])   # lw a1,0(a0) against lw a0,0(a1): registers only
check(sc["reg"] == 1 and sc["hard"] == 0 and sc["score"] == 0.25, f"score.score register-only {sc}")
sc = score.score([1, 2, 3, 4, 5], [1, 9, 2, 3, 4, 5])   # one inserted instruction: the aligned tail is not a diff of its own
check(sc["size"] == 1 and sc["edit"] == 1 and sc["score"] == 1, f"score.score insertion {sc}")

import objcache  # noqa: E402
import tempfile  # noqa: E402
with tempfile.TemporaryDirectory() as td:
    empty, full = Path(td, "e.o"), Path(td, "f.o")
    empty.write_bytes(b"")
    full.write_bytes(b"x")
    check(not objcache.good(empty) and not empty.exists() and objcache.good(full), "objcache.good deletes an empty object")
    # deps: only the headers a source can reach change its key, through a nested include and through a header that appears
    for name, text in (("a.h", '#include <b.h>\n'), ("inc/b.h", "int b;\n"), ("inc/other.h", "int o;\n")):
        Path(td, name).parent.mkdir(exist_ok=True)
        Path(td, name).write_text(text)
    dep = lambda: (objcache._HDR.clear(), objcache._REACH.clear(), objcache.deps(b'#include "a.h"\n', Path(td, "x.c"), ["-O2", "-I" + td + "/inc"]))[2]
    d0 = dep()
    Path(td, "inc/other.h").write_text("int changed;\n")
    d1 = dep()
    Path(td, "inc/b.h").write_text("int changed;\n")
    d2 = dep()
    Path(td, "b.h").write_text("int shadows;\n")   # found first by the compiler: next to the file that includes it
    check(d0 == d1 and d1 != d2 and d2 != dep(), "objcache.deps follows the headers a file can reach, and only those")
    # trim: over the cap, the least recently used objects go first, down to 80 % of it; one used in the last hour never goes
    import os, time  # noqa: E402
    saved = objcache.CACHE, objcache.MAX
    objcache.CACHE, objcache.MAX = Path(td, "cache"), 5 * 8192
    Path(td, "cache/obj").mkdir(parents=True)
    for i in range(8):   # 8 objects of 8192 bytes, i hours old; number 0 is used now
        Path(td, f"cache/obj/{i}.o").write_bytes(b"x" * 8192)
        os.utime(Path(td, f"cache/obj/{i}.o"), (time.time() - 3600 * i - 60,) * 2)
    freed = objcache.trim(force=True)
    left = sorted(p.name for p in Path(td, "cache/obj").iterdir())
    check(freed == 4 * 8192 and left == ["0.o", "1.o", "2.o", "3.o"], f"objcache.trim deletes the least recently used objects ({freed}, {left})")
    objcache.MAX = 0
    check(objcache.trim() == 0 and objcache.trim(force=True) == 3 * 8192 and Path(td, "cache/obj/0.o").exists(),
          "objcache.trim scans once every five minutes and keeps an object used in the last hour")
    objcache.CACHE, objcache.MAX = saved

import server  # noqa: E402
import client  # noqa: E402
import threading  # noqa: E402
import time  # noqa: E402
server.HOME, server.TMP = Path(tempfile.mkdtemp()), Path(tempfile.mkdtemp())
server.JOBS = 2
server.SEM = threading.BoundedSemaphore(2)
peak, cur, lk = [0], [0], threading.Lock()


def job():
    with server.gate():
        with lk:
            cur[0] += 1
            peak[0] = max(peak[0], cur[0])
        time.sleep(0.05)
        with lk:
            cur[0] -= 1


ts = [threading.Thread(target=job) for _ in range(6)]
[t.start() for t in ts]
[t.join() for t in ts]
check(peak[0] == 2 and server.STATE["running"] == 0 and server.STATE["waiting"] == 0, f"server.gate runs 2 at a time, peak {peak[0]}")
check(client.local("C:\\Users\\x\\a.c") == Path("/mnt/c/Users/x/a.c") and client.local("src/a.c") == Path("src/a.c"), "client.local")
r = server.do_match({"id": 7, "seg": "boot", "fn": "no_such_function", "source": "void f(void) {}\n"})
check(r["id"] == 7 and r["status"] == "ERROR" and not r["match"], f"server.do_match reports an error {r}")

import struct  # noqa: E402
import hardjt  # noqa: E402
check(hardjt.tables_agree([(0, 0x100), (4, 0x110), (8, 0x100)], 0x100, [[0x1000, 0x1010, 0x1000]], 0x1000), "hardjt.tables_agree: entries are offsets from the function")
check(not hardjt.tables_agree([(0, 0x100), (8, 0x110)], 0x100, [[0x1000, 0x1010]], 0x1000), "hardjt.tables_agree: a gap between words is no table")
check(hardjt.bound("a\n  sltiu $at, $t6, 0x5\n  lui $at, %hi(jtbl_80000000)\n", "jtbl_80000000") == 5, "hardjt.bound")

import hard_blocks  # noqa: E402
check(hard_blocks.kind(0x10400003) == "branch" and hard_blocks.kind(0x0C000010) == "jump" and hard_blocks.kind(0x03E00008) == "jr", "hard_blocks.kind")
nop, add = 0, 0x24020001
_a, _b, _pairs, _exact, _ = hard_blocks.compare(struct.pack(">3I", add, nop, 0x03E00008), struct.pack(">4I", add, nop, nop, 0x03E00008), {})
check(len(_pairs) == 3 and all(_exact.values()), "hard_blocks.compare aligns across an inserted instruction")

import hard_hand  # noqa: E402
check(hard_hand.classify("  /* 0 80000000 40846800 */  mtc0       $a0, $13\n", 12)[0] == "asm_only"
      and hard_hand.classify("  /* 0 80000000 03E00008 */  jr         $ra\n", 8)[0] == "c-candidate", "hard_hand.classify")

print(f"{len(failures)} failure(s)" if failures else "selftest: OK")
sys.exit(1 if failures else 0)
