#!/usr/bin/env python3
"""Functions with a jump table (switch): m2c refuses them (`the corresponding jump table is not provided`), because the splat assembly keeps the
table as raw words. This tool gives m2c the table.
  hard_jt.py draft <seg> <fn>             print the m2c draft with the table (WSL, venv)
  hard_jt.py info  <seg> <fn>             tables, case values per target
  hard_jt.py auto  <seg|overlays> [max_size_hex=0x400] [jobs=3]
                                          draft every unmatched function that has a table, try the usual flag sets, check the table against the
                                          ROM; matches go to build/auto_match/<seg>_jt/<fn>.c (log build/auto_match/<seg>_jt.txt, resume-safe)
  hard_jt.py check <seg> <fn> <file.c>    match.py plus the table: the case targets of our object, as offsets in the function, must be the ROM's
The table of an overlay is not compared by match.py (the file holds link-time addresses, see docs/OVERLAYS.md); `check` compares it through the
relocations of our object (R_MIPS_32 in .rodata against .text), which is the same information."""
import re, subprocess, sys, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import auto_match as am  # noqa: E402
import auto_near as an  # noqa: E402
import auto_recipes as ar  # noqa: E402
import hard_scan  # noqa: E402
import hardjt  # noqa: E402
import match  # noqa: E402
import objcache  # noqa: E402

M2C = ROOT / "tools/vendor/m2c/m2c.py"


def function_chunk(seg, fn):
    return next(c for c in hardjt.chunks(seg) if c[0] == fn)


def m2c_input(seg, fn):
    """The function and its tables as m2c wants them: labels at the case targets, `.word .Lxxxx` entries under `glabel jtbl_*`."""
    text = function_chunk(seg, fn)[3]
    tabs = hardjt.head_tables(seg, fn)
    targets = {e for _, ents in tabs for e in ents}
    out = []
    for line in text.splitlines():
        m = re.match(r"\s*/\*\s+\w+\s+([0-9A-Fa-f]{8})\s+[0-9A-Fa-f]{8}\s*\*/", line)
        if m and int(m.group(1), 16) in targets:
            lab = f"  .L{int(m.group(1), 16):08X}:"
            if not (out and out[-1].strip() == lab.strip()):
                out.append(lab)
        out.append(line)
    body = "\n".join(l for l in out if not l.startswith("nonmatching"))
    ro = ".section .rodata\n"
    for lab, ents in tabs:
        ro += f"glabel {lab}\n" + "".join(f"    .word .L{e:08X}\n" for e in ents)
    return body + "\n\n" + ro


def asm_head(seg):
    t = hardjt.asm_path(seg).read_text()
    return t[:t.index("nonmatching ")]


def draft(seg, fn):
    """(m2c text or None, message). Needs m2c (the venv of WSL)."""
    with tempfile.TemporaryDirectory() as d:
        s = Path(d) / f"{fn}.s"
        s.write_text(asm_head(seg) + m2c_input(seg, fn))
        r = subprocess.run([sys.executable, str(M2C), "-t", "mips-ido-c", "--valid-syntax", "-f", fn, str(s)], capture_output=True, text=True)
    if r.returncode or "Decompilation failure" in r.stdout or not re.search(rf"[ *]{fn}\(", r.stdout):
        return None, r.stdout + r.stderr
    return r.stdout, ""


def cases(seg, fn):
    """{table: {target: [case values]}}."""
    res = {}
    for lab, ents in hardjt.head_tables(seg, fn):
        m = {}
        for i, e in enumerate(ents):
            m.setdefault(e, []).append(i)
        res[lab] = m
    return res


def table_ok(seg, fn, cfile, flags):
    """The jump tables of our object are the ROM's (case targets as offsets from the function start)."""
    obj = objcache.compile_obj(cfile, flags + am.BASE)
    name = match.real_name(cfile, fn)
    _, _, inside, _ = match.elf_text(str(obj))
    if name not in inside:
        name = fn
    start = inside[name][0]
    tabs = [ents for _, ents in hardjt.head_tables(seg, fn)]
    return hardjt.tables_agree(hardjt.object_tables(str(obj)), start, tabs, int(fn[-8:], 16))


def verdict(seg, fn, cfile, flags):
    """'MATCH' when the code and the tables agree with the ROM, else a short reason."""
    want, _ = match.original(seg, fn)
    if not am.same(want, cfile, fn, flags):
        return "code differs"
    return "MATCH" if table_ok(seg, fn, cfile, flags) else "tables differ"


def attempt(job):
    seg, fn = job
    text, err = draft(seg, fn)
    if text is None:
        return seg, fn, "m2c failed", None
    src = ('#include "types.h"\n#include "m2c_compat.h"\n\n' + text.replace("void *", "u8 *").replace("M2C_UNK8", "M2C_UNK")
           .replace("M2C_UNK16", "M2C_UNK").replace("M2C_UNK32", "M2C_UNK"))
    with tempfile.TemporaryDirectory() as d:
        c = Path(d) / f"{fn}.c"
        c.write_text(src)
        seen = set()
        for flags in am.FLAG_SETS:
            v = verdict(seg, fn, c, flags)
            seen.add(v)
            if v == "MATCH":
                return seg, fn, "MATCH " + " ".join(flags), f"// FLAGS: {' '.join(flags)}\n" + src
        # the mechanical tricks of auto_recipes on the two flag sets that come closest, when the draft is close at all
        want, _ = match.original(seg, fn)
        scored = sorted((r[0] / r[1] if r else 9, fl) for fl in am.FLAG_SETS for r in [an.ndiff(want, c, fn, fl)])
        if scored[0][0] <= 0.3:
            for desc, variant in ar.variants(text.replace("void *", "u8 *")):
                vsrc = '#include "types.h"\n#include "m2c_compat.h"\n\n' + variant
                c.write_text(vsrc)
                for _, fl in scored[:2]:
                    if verdict(seg, fn, c, fl) == "MATCH":
                        return seg, fn, f"MATCH {desc} {' '.join(fl)}", f"// FLAGS: {' '.join(fl)}\n" + vsrc
    return seg, fn, "no match" + (" (tables differ)" if "tables differ" in seen else ""), None


def cmd_auto(args):
    redo = "--redo" in args   # try again what the log says did not match (a better pass was added)
    args = [a for a in args if a != "--redo"]
    which = args[0]
    mx = int(args[1], 16) if len(args) > 1 else 0x400
    jobs = int(args[2]) if len(args) > 2 else 3
    from multiprocessing import Pool
    todo = []
    for seg in hard_scan.segments([which]):
        log = ROOT / "build/auto_match" / f"{seg}_jt.txt"
        done = {l.split()[0] for l in log.read_text().splitlines()
                if not redo or "MATCH" in l} if log.exists() else set()
        todo += [(seg, fn) for fn, size, cats in hard_scan.scan(seg) if "jtbl" in cats and size <= mx and fn not in done
                 and (not seg.startswith("ovl") or hardjt.link_base(seg))]
    print(f"{len(todo)} functions to try", flush=True)
    won = 0
    with Pool(jobs) as pool:
        for seg, fn, status, src in pool.imap_unordered(attempt, todo):
            log = ROOT / "build/auto_match" / f"{seg}_jt.txt"
            log.parent.mkdir(parents=True, exist_ok=True)
            if src:
                out = ROOT / "build/auto_match" / f"{seg}_jt"
                out.mkdir(exist_ok=True)
                (out / f"{fn}.c").write_text(src)
                won += 1
            with log.open("a") as lf:
                lf.write(f"{fn} {status}\n")
    print(f"DONE: {won} matched out of {len(todo)}")


def cmd_check(seg, fn, cfile):
    cfile = Path(cfile)
    m = re.match(r"// FLAGS: (.*)", cfile.read_text().splitlines()[0])
    v = verdict(seg, fn, cfile, m.group(1).split() if m else am.FLAG_SETS[0])
    print(f"{fn}: {v}")
    sys.exit(0 if v == "MATCH" else 1)


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    if sys.argv[1] == "auto":
        return cmd_auto(sys.argv[2:])
    if len(sys.argv) < 4:
        sys.exit(__doc__)
    cmd, seg, fn = sys.argv[1:4]
    if cmd == "check" and len(sys.argv) > 4:
        cmd_check(seg, fn, sys.argv[4])
    elif cmd == "draft":
        out, err = draft(seg, fn)
        print(out or err)
    elif cmd == "info":
        for lab, m in cases(seg, fn).items():
            print(lab)
            for t, vals in sorted(m.items()):
                print(f"  {t:#010x}: {vals}")
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
