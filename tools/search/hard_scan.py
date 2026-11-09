#!/usr/bin/env python3
"""Count and list the unmatched functions the automatic tools skip, by category.
usage: hard_scan.py [boot|code|overlays|ovlNNNN ...] [--list CATEGORY] [--max-size HEX]
Categories (a function can be in several): jtbl (jump table in its code), hand (already outside the C todo: marked `Handwritten function` by
splat or listed in config/<seg>/asm_only.txt), hand_unlisted (privileged instructions, neither marked nor listed: hard_hand.py), m2c_failed
(the auto_match log says `m2c failed`), large (more than 0x400 bytes), other (none of those).
A function counts as unmatched when no verified C file exists (wip does not count)."""
import collections, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import srcpath  # noqa: E402

# instructions IDO never emits for C (cfc1/ctc1 and break are not here: IDO uses them for float to unsigned conversions and divide checks)
HAND = re.compile(r"^\s*/\*.*?\*/\s+(mtc0|mfc0|dmtc0|dmfc0|eret|cache|ll|sc|lld|scd|tlbr|tlbwi|tlbwr|tlbp|sync|syscall)\s", re.M)
LARGE = 0x400
CHUNK = re.compile(r"(?=^nonmatching )", re.M)


def segments(args):
    out = []
    for a in args or ["boot", "code", "overlays"]:
        if a == "overlays":
            out += ["ovl" + d.name for d in sorted((ROOT / "asm/overlays").iterdir()) if (d / "text.s").exists()]
        else:
            out.append(a)
    return out


def verified(seg, fn):
    if seg.startswith("ovl"):
        return (srcpath.overlay_dir(seg[3:]) / f"{fn}.c").exists()
    return srcpath.path(seg, fn).exists()


def m2c_failed(seg):
    log = ROOT / "build/auto_match" / f"{seg}.txt"
    return {l.split()[0] for l in log.read_text().splitlines() if l.endswith("m2c failed")} if log.exists() else set()


def scan(seg):
    """[(fn, size, categories)] of the unmatched functions of a segment."""
    asm = ROOT / (f"asm/overlays/{seg[3:]}/text.s" if seg.startswith("ovl") else f"asm/{seg}/text.s")
    skip = ROOT / "config" / seg / "asm_only.txt"
    asm_only = set(skip.read_text().split()) if skip.exists() else set()
    failed = m2c_failed(seg)
    res = []
    full = asm.read_text()
    marked = set(re.findall(r"/\* Handwritten function \*/\nnonmatching (\w+)", full))   # splat's own mark: built from the assembly, not counted as C todo
    for ch in CHUNK.split(full)[1:]:
        m = re.match(r"nonmatching (\w+), (0x[0-9A-Fa-f]+)", ch)
        if not m or verified(seg, m.group(1)):
            continue
        fn, size = m.group(1), int(m.group(2), 16)
        cats = set()
        if "%hi(jtbl_" in ch or "%lo(jtbl_" in ch:
            cats.add("jtbl")
        if fn in marked or fn in asm_only:
            cats.add("hand")   # already outside the C todo (progress.py): splat's `Handwritten function` or config/<seg>/asm_only.txt
        elif HAND.search(ch):
            cats.add("hand_unlisted")   # privileged instructions but not marked: see hard_hand.py
        if fn in failed:
            cats.add("m2c_failed")
        if size > LARGE:
            cats.add("large")
        res.append((fn, size, cats or {"other"}))
    return res


def main():
    args = sys.argv[1:]
    want = None
    if "--list" in args:
        i = args.index("--list")
        want = args[i + 1]
        del args[i:i + 2]
    mx = None
    if "--max-size" in args:
        i = args.index("--max-size")
        mx = int(args[i + 1], 16)
        del args[i:i + 2]
    total = collections.Counter()
    per = collections.defaultdict(collections.Counter)
    for seg in segments(args):
        group = seg if seg in ("boot", "code") else "overlays"
        for fn, size, cats in scan(seg):
            if mx and size > mx:
                continue
            total[group] += 1
            for c in cats:
                per[group][c] += 1
            if want and want in cats:
                print(seg, fn, hex(size))
    if not want:
        for g in total:
            print(f"{g}: {total[g]} unmatched; " + ", ".join(f"{k} {v}" for k, v in sorted(per[g].items())))


if __name__ == "__main__":
    main()
