#!/usr/bin/env python3
"""Apply a table of professional signatures to verified C functions, and keep a file only if it still matches the ROM. Run in WSL.
usage: retype.py <table> [--dry] [-j N]
Table line:  <segment> <function> <header.h> <prototype>   [# evidence]      (segment: boot, code or ovlNNNN)
    ovl0057 func_800007A0 actor.h void func_800007A0(Actor *thisx, PlayState *play)   # update slot of the actor profile
For each function with a verified source file the tool
  1. replaces the signature (same number of parameters) and renames the parameters in the body,
  2. casts a renamed parameter used as `p + N` to `(u8 *)p + N` (the body was written for a byte or integer parameter),
  3. adds `#include "<header>"` after the last include,
  4. compiles the result with the flags of the file and compares it with the ROM bytes (tools/match.py rules),
and restores the previous text when anything fails (a clash of names, a type that is already defined locally, a different byte).
A function without a source file yet is skipped: run the tool again when it has one. Summary: converted / already / failed / pending."""
import re, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import match  # noqa: E402
import objcache  # noqa: E402
import srcpath  # noqa: E402

PARAM = re.compile(r"^(?P<type>.*?[\s\*])(?P<name>\w+)$")


def source(seg: str, fn: str) -> Path:
    if seg.startswith("ovl"):
        return ROOT / "src" / "overlays" / seg[3:] / f"{fn}.c"
    return srcpath.path(seg, fn)


def params(text: str):
    """[(type, name)] of a parameter list; None when it is not a plain list (function pointer, varargs)."""
    text = text.strip()
    if text in ("", "void"):
        return []
    out = []
    for p in (x.strip() for x in text.split(",")):
        m = PARAM.match(p)
        if "(" in p or p == "..." or not m:
            return None
        out.append((m.group("type").strip(), m.group("name")))
    return out


def matches(seg: str, fn: str, path: Path) -> bool:
    try:
        want, _ = match.original(seg, fn)
        got, masks = match.compiled(path, fn, match.file_flags(path), len(want))
    except Exception:
        return False
    if len(got) > len(want) and not any(got[len(want):]):
        got = got[:len(want)]
    return len(got) == len(want) and match.mask(want, masks) == match.mask(got, masks)


def rewrite(text: str, fn: str, header: str, proto: str):
    """(new text, reason): the reason is empty on success."""
    pm = re.match(r"^(?P<ret>.*?[\s\*])" + re.escape(fn) + r"\s*\((?P<args>.*)\)\s*;?$", proto.strip())
    if not pm:
        return None, "bad prototype"
    new = params(pm.group("args"))
    dm = re.search(r"^(?P<ret>[^\n;{}()]*?[\s\*])" + re.escape(fn) + r"\((?P<args>[^)]*)\)\s*\{", text, re.M)
    if new is None or not dm:
        return None, "definition not found"
    old = params(dm.group("args"))
    if old is None or len(old) != len(new):
        return None, "different parameter count"
    head, body = text[:dm.start()], text[dm.end():]
    for (ot, on), (nt, nn) in zip(old, new):
        if on != nn:
            if re.search(r"\b" + re.escape(nn) + r"\b", head + body):
                return None, f"name {nn} already used"
            body = re.sub(r"\b" + re.escape(on) + r"\b", nn, body)
        if "*" in nt:  # the body did arithmetic on a byte or integer parameter: a typed pointer would scale it
            body = re.sub(r"\b" + re.escape(nn) + r"\b(\s*[-+]\s*(?:0x[0-9A-Fa-f]+|\d+)\b)", lambda m: "(u8 *)" + nn + m.group(1), body)
    sig = pm.group("ret").strip() + " " + fn + "(" + ", ".join(f"{t}{'' if t.endswith('*') else ' '}{n}" for t, n in new) + ") {"
    sig = sig.replace("* ", "*") if False else sig
    out = head + sig + body
    inc = f'#include "{header}"'
    if inc not in out:
        lines = out.split("\n")
        last = max((i for i, l in enumerate(lines) if l.startswith("#include")), default=-1)
        lines.insert(last + 1, inc)
        out = "\n".join(lines)
    return out, ""


def work(entry):
    seg, fn, header, proto = entry
    path = source(seg, fn)
    if not path.exists():
        return entry, "pending", ""
    old = path.read_text()
    if f'#include "{header}"' in old and proto.rstrip(";") in old:
        return entry, "already", ""
    new, why = rewrite(old, fn, header, proto)
    if new is None:
        return entry, "failed", why
    path.write_text(new)
    if matches(seg, fn, path):
        return entry, "converted", ""
    path.write_text(old)
    return entry, "failed", "no longer matches (or does not compile)"


def parse(table: Path):
    for line in table.read_text().splitlines():
        line = line.split("#", 1)[0].strip()
        if line:
            seg, fn, header, proto = line.split(None, 3)
            yield seg, fn, header, proto


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("-")]
    jobs = int(sys.argv[sys.argv.index("-j") + 1]) if "-j" in sys.argv else objcache.JOBS
    entries = list(parse(Path(args[0])))
    if "--dry" in sys.argv:
        got = sum(source(s, f).exists() for s, f, _, _ in entries)
        print(f"{len(entries)} entries, {got} with a verified source file")
        return
    count, why = {}, {}
    with ThreadPoolExecutor(jobs) as ex:
        for (seg, fn, _, _), state, reason in ex.map(work, entries):
            count[state] = count.get(state, 0) + 1
            if state == "failed":
                why[reason] = why.get(reason, 0) + 1
    print(" ".join(f"{k}={v}" for k, v in sorted(count.items())))
    for r, n in sorted(why.items(), key=lambda kv: -kv[1]):
        print(f"  failed {n}: {r}")


if __name__ == "__main__":
    main()
