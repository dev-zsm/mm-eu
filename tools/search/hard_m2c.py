#!/usr/bin/env python3
"""Drafts for the functions on which the plain m2c run fails (auto_match.py logs them as `m2c failed`), and the reasons why it fails.
Run in WSL (venv).
  hard_m2c.py why  <seg|overlays> [limit=200]   run m2c on the `m2c failed` functions, count the reasons (first line of its message)
  hard_m2c.py draft <seg> <fn>                  the first variant that gives C: the table for a switch (hard_jt.py), then the options below
  hard_m2c.py auto <seg|overlays> [max_size_hex=0x400] [jobs=3]
                                                 try the variants x flag sets on every `m2c failed` function; matches go to
                                                 build/auto_match/<seg>_fb/<fn>.c (log <seg>_fb.txt, resume-safe)
Variants (m2c options): plain, --gotos-only (no control flow recovery: always works, the C is ugly but compiles to the same branches more
often than one expects), --no-andor, --no-switches, --reg-vars for the registers the draft names most. The reasons m2c refuses a function
and what to do about each are in docs/TOOLS.md."""
import collections, re, subprocess, sys, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import auto_match as am  # noqa: E402
import hard_jt  # noqa: E402
import hard_scan  # noqa: E402
import hardjt  # noqa: E402
import match  # noqa: E402

VARIANTS = [[], ["--gotos-only"], ["--no-andor"], ["--no-switches"], ["--gotos-only", "--no-andor"], ["--no-stack-spill"]]
FIX = (("void *", "u8 *"), ("M2C_UNK8", "M2C_UNK"), ("M2C_UNK16", "M2C_UNK"), ("M2C_UNK32", "M2C_UNK"))


def run_m2c(seg, fn, opts, asm):
    with tempfile.TemporaryDirectory() as d:
        s = Path(d) / f"{fn}.s"
        s.write_text(asm)
        r = subprocess.run([sys.executable, str(am.M2C), "-t", "mips-ido-c", "--valid-syntax", "-f", fn, *opts, str(s)], capture_output=True, text=True)
    out = r.stdout
    bad = r.returncode or "Decompilation failure" in out or not re.search(rf"[ *]{fn}\(", out)
    return (None, out + r.stderr) if bad else (out, "")


def function_asm(seg, fn):
    """The asm m2c reads: with the jump tables when the function has any."""
    chunk = hard_jt.function_chunk(seg, fn)[3]
    head = hard_jt.asm_head(seg)
    if hardjt.JTBL_USE.search(chunk) and hardjt.head_tables(seg, fn):
        return head + hard_jt.m2c_input(seg, fn)
    return head + chunk


def reason(msg):
    """The first meaningful line of an m2c failure, with addresses and names removed so the lines can be counted."""
    lines = [l.strip() for l in msg.splitlines() if l.strip() and not l.startswith(("/*", "*/", "Decompilation failure"))]
    line = lines[0] if lines else "(no message)"
    return re.sub(r"\b(func|D|jtbl)_[0-9A-F]{8}\b|\.L[0-9A-F]{8}|0x[0-9A-Fa-f]+|\b\d+\b", "N", line)[:110]


def draft(seg, fn):
    """(text, options used, messages)."""
    asm, msgs = function_asm(seg, fn), []
    for opts in VARIANTS:
        out, err = run_m2c(seg, fn, opts, asm)
        if out is not None:
            return out, opts, msgs
        msgs.append(reason(err))
    return None, None, msgs


def attempt(job):
    seg, fn = job
    out, opts, msgs = draft(seg, fn)
    if out is None:
        return seg, fn, "no draft", None
    text = out   # a function with a jump table also has to agree with the ROM's table (hard_jt.verdict)
    for a, b in FIX:
        text = text.replace(a, b)
    src = '#include "types.h"\n#include "m2c_compat.h"\n\n' + text
    with tempfile.TemporaryDirectory() as d:
        c = Path(d) / f"{fn}.c"
        c.write_text(src)
        table = bool(hardjt.JTBL_USE.search(hard_jt.function_chunk(seg, fn)[3]))
        for flags in am.FLAG_SETS:
            ok = hard_jt.verdict(seg, fn, c, flags) == "MATCH" if table else am.same(match.original(seg, fn)[0], c, fn, flags)
            if ok:
                return seg, fn, f"MATCH {' '.join(opts)} {' '.join(flags)}", f"// FLAGS: {' '.join(flags)}\n" + src
    return seg, fn, f"no match ({' '.join(opts) or 'plain'})", None


def failed_of(seg):
    log = ROOT / "build/auto_match" / f"{seg}.txt"
    return [l.split()[0] for l in log.read_text().splitlines() if l.endswith("m2c failed")] if log.exists() else []


def cmd_why(args):
    segs = hard_scan.segments([args[0]])
    limit = int(args[1]) if len(args) > 1 else 200
    count, example = collections.Counter(), {}
    for seg in segs:
        for fn in failed_of(seg):
            if sum(count.values()) >= limit:
                break
            out, err = run_m2c(seg, fn, [], function_asm(seg, fn))
            r = "m2c gives C now (the log line came from the `void *name(` check of auto_match, fixed)" if out is not None else reason(err)
            count[r] += 1
            example.setdefault(r, f"{seg} {fn}")
    for r, n in count.most_common():
        print(f"{n:4}  {r}   e.g. {example[r]}")


def cmd_auto(args):
    from multiprocessing import Pool
    mx = int(args[1], 16) if len(args) > 1 else 0x400
    jobs = int(args[2]) if len(args) > 2 else 3
    todo = []
    for seg in hard_scan.segments([args[0]]):
        log = ROOT / "build/auto_match" / f"{seg}_fb.txt"
        done = {l.split()[0] for l in log.read_text().splitlines()} if log.exists() else set()
        sizes = {fn: size for fn, size, _ in hard_scan.scan(seg)}
        todo += [(seg, fn) for fn in failed_of(seg) if fn in sizes and sizes[fn] <= mx and fn not in done]
    print(f"{len(todo)} functions to try", flush=True)
    won = 0
    with Pool(jobs) as pool:
        for seg, fn, status, src in pool.imap_unordered(attempt, todo):
            log = ROOT / "build/auto_match" / f"{seg}_fb.txt"
            if src:
                out = ROOT / "build/auto_match" / f"{seg}_fb"
                out.mkdir(parents=True, exist_ok=True)
                (out / f"{fn}.c").write_text(src)
                won += 1
            with log.open("a") as lf:
                lf.write(f"{fn} {status}\n")
    print(f"DONE: {won} matched out of {len(todo)}")


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    cmd = sys.argv[1]
    if cmd == "why":
        cmd_why(sys.argv[2:])
    elif cmd == "auto":
        cmd_auto(sys.argv[2:])
    elif cmd == "draft" and len(sys.argv) > 3:
        out, opts, msgs = draft(sys.argv[2], sys.argv[3])
        print(f"/* m2c options: {' '.join(opts) if opts else 'plain'}; refused before: {msgs} */\n" + out if out else "no variant gives C: " + "; ".join(msgs))
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
