#!/usr/bin/env python3
"""Classify the difference between each unfinished draft and the ROM, to choose the right tool. CPU only. Run in WSL.
usage: diff_kind.py <seg>      writes build/diff_kind_<seg>.txt: `<fn> <kind> <n differing instructions>`
Kinds: size (different size), order (same instructions, different order: scheduling, store order), registers (same
opcodes in the same order, other registers), other. `order` and `registers` are the ones the permuter solves best."""
import re, sys
from collections import Counter
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import match
import srcpath  # noqa: F401

BASE = match.DEFAULT_FLAGS[3:]


def words(b):
    return [int.from_bytes(b[i:i + 4], "big") for i in range(0, len(b) - len(b) % 4, 4)]


def kind(want, got, masks):
    if len(want) != len(got):
        return "size", abs(len(want) - len(got)) // 4
    a, b = match.mask(want, masks), match.mask(got, masks)
    bad = sum(x != y for x, y in zip(a, b))
    if not bad:
        return "match", 0
    if Counter(a) == Counter(b):
        return "order", bad
    if all((x >> 26) == (y >> 26) for x, y in zip(a, b)):  # same major opcode everywhere: only operands differ
        return "registers", bad
    return "other", bad


def main():
    seg = sys.argv[1]
    out, counts = [], Counter()
    for f in sorted((match.ROOT / "src" / seg / "wip").glob("func_*.c")) if seg in ("boot", "code") else \
            sorted((match.ROOT / "src" / "overlays").glob("*/wip/func_*.c")):
        fn = f.stem
        s = seg if seg in ("boot", "code") else f"ovl{f.parent.parent.name}"
        try:
            want, _ = match.original(s, fn)
            got, masks = match.compiled(f, fn, match.file_flags(f), len(want))
            if len(got) > len(want) and not any(got[len(want):]):
                got = got[:len(want)]
            k, n = kind(want, got, masks)
        except Exception:
            k, n = "nocompile", 0
        counts[k] += 1
        out.append(f"{s} {fn} {k} {n}")
    (match.ROOT / "build" / f"diff_kind_{seg}.txt").write_text("\n".join(out) + "\n")
    print(seg, dict(counts))


if __name__ == "__main__":
    main()
