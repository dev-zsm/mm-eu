#!/usr/bin/env python3
"""Apply the mechanical tricks the agents found to every automatic draft, and keep exact matches.
Run in WSL (venv, MM_CC set).  usage: auto_recipes.py <seg> [max_size_hex=0x100] [jobs=2]
Recipes (each tried alone and with the address-order cast): change one parameter's type (s32/u32/s16/u16/s8/u8/f32),
add stack padding (first or last in the declarations), force the `addu` operand order with (u8 *)((s32)p + n).
Matches go to build/auto_match/<seg>_recipes/<fn>.c (review, then move to src/<seg>/ like auto_match output);
log: build/auto_match/<seg>_recipes.txt (resume-safe)."""
import re, subprocess, sys, tempfile
from multiprocessing import Pool
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import auto_match as am  # noqa: E402
import auto_near as an  # noqa: E402
import match  # noqa: E402

TYPES = ["s32", "u32", "s16", "u16", "s8", "u8", "f32"]
SIG = re.compile(r"^(?P<ret>[\w ]+?[ *])(?P<fn>func_\w+)\((?P<args>[^)]*)\) \{", re.M)


def variants(src: str):
    """Yield (description, source) for every recipe."""
    base = [("plain", src)]
    addu = re.sub(r"\b(arg\d) \+ (0x[0-9A-Fa-f]+|\d+)\b", r"(u8 *)((s32)\1 + \2)", src)
    if addu != src:
        base.append(("addu-cast", addu))
    for tag, s in base:
        yield tag, s
        m = SIG.search(s)
        if not m:
            continue
        args = [a.strip() for a in m.group("args").split(",")] if m.group("args").strip() not in ("", "void") else []
        for i, a in enumerate(args[:4]):
            mt = re.match(r"(s32|u32|s16|u16|s8|u8|f32|f64)\s+(arg\d)$", a)
            if not mt:
                continue
            for t in TYPES:
                if t != mt.group(1):
                    na = list(args); na[i] = f"{t} {mt.group(2)}"
                    yield f"{tag}+{mt.group(2)}:{t}", s[:m.start("args")] + ", ".join(na) + s[m.end("args"):]
        body = m.end()
        for pad in ("s32 pad;", "s32 pad[2];", "s32 pad[4];"):
            yield f"{tag}+pad-first:{pad}", s[:body] + f"\n    {pad}" + s[body:]
            end = s.find("\n\n", body)
            if end > 0:
                yield f"{tag}+pad-last:{pad}", s[:end] + f"\n    {pad}" + s[end:]


def attempt(job):
    seg, fn, want, asm = job
    with tempfile.TemporaryDirectory() as d:
        s = Path(d) / f"{fn}.s"
        s.write_text(asm)
        r = subprocess.run([sys.executable, str(am.M2C), "-t", "mips-ido-c", "--valid-syntax", str(s)],
                           capture_output=True, text=True)
        if r.returncode or f" {fn}(" not in r.stdout:
            return fn, "m2c failed", None
        body = r.stdout.replace("void *", "u8 *").replace("M2C_UNK8", "M2C_UNK").replace("M2C_UNK16", "M2C_UNK").replace("M2C_UNK32", "M2C_UNK")
        c = Path(d) / f"{fn}.c"
        # best two flag sets on the plain draft, by distance (size mismatch counts as far)
        c.write_text('#include "types.h"\n#include "m2c_compat.h"\n\n' + body)
        scored = []
        for fl in am.FLAG_SETS:
            res = an.ndiff(want, c, fn, fl)
            scored.append((res[0] if res else 10**6, fl))
        flagsets = [fl for _, fl in sorted(scored, key=lambda x: x[0])[:2]]
        for desc, v in variants(body):
            c.write_text('#include "types.h"\n#include "m2c_compat.h"\n\n' + v)
            for fl in flagsets:
                if am.same(want, c, fn, fl):
                    return fn, f"MATCH {desc} {' '.join(fl)}", f"// FLAGS: {' '.join(fl)}\n" + c.read_text()
    return fn, "no match", None


def main():
    seg = sys.argv[1]
    max_size = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x100
    jobs = int(sys.argv[3]) if len(sys.argv) > 3 else 2
    text = (ROOT / "asm" / seg / "text.s").read_text()
    head = text[:text.index("nonmatching ")]
    out = ROOT / "build/auto_match" / f"{seg}_recipes"
    out.mkdir(parents=True, exist_ok=True)
    log = out.parent / f"{seg}_recipes.txt"
    done = {l.split()[0] for l in log.read_text().splitlines()} if log.exists() else set()
    failed = {l.split()[0] for l in (out.parent / f"{seg}.txt").read_text().splitlines() if l.endswith(" no match")}
    path, base = match.SEG[seg]
    rom = path.read_bytes()
    todo = []
    for ch in re.split(r"(?=^nonmatching )", text, flags=re.M)[1:]:
        m = re.match(r"nonmatching (\w+), (0x[0-9A-Fa-f]+)", ch)
        if not m or m.group(1) not in failed or m.group(1) in done or (ROOT / "src" / seg / f"{m.group(1)}.c").exists():
            continue
        fn, size = m.group(1), int(m.group(2), 16)
        if size <= max_size:
            off = int(fn[-8:], 16) - base
            todo.append((size, (seg, fn, rom[off:off + size], head + ch)))
    todo = [j for _, j in sorted(todo, key=lambda t: t[0])]
    print(f"{len(todo)} drafts to try", flush=True)
    won = 0
    with Pool(jobs) as pool, log.open("a") as lf:
        for fn, status, src in pool.imap_unordered(attempt, todo):
            if src:
                (out / f"{fn}.c").write_text(src)
                won += 1
            lf.write(f"{fn} {status}\n")
            lf.flush()
    print(f"DONE: {won} matched out of {len(todo)}")


if __name__ == "__main__":
    main()
