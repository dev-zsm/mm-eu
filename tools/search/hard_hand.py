#!/usr/bin/env python3
"""Classify the unmatched functions that look hand-written: which cannot be C (asm_only candidates) and which only look odd.
usage: hard_hand.py [boot|code|overlays|ovlNNNN ...] [--apply]
For every unmatched function (no verified C file) the instructions give evidence:
  asm_only   (solid)   an instruction IDO never emits for C: COP0 (mtc0, mfc0, eret, tlb*), cache, ll/sc, sync, syscall, a use of $k0/$k1 as a register,
                       or a floating point status register access with no call (`cfc1`/`ctc1` as the whole point of the function: osGetFpcCsr/osSetFpcCsr)
  c-candidate          no such evidence: written in C even if it looks odd (hand copy loops with lwl/lwr/swl/swr, filled delay slots, tail jumps).
                       The list says what makes it look odd, so an agent can start with the right idiom.
--apply appends the solid ones to config/<seg>/asm_only.txt (boot, code; one name per line, sorted, existing lines kept); overlays are listed only
(an overlay has no asm_only file: its functions are not built from assembly)."""
import re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import hard_scan  # noqa: E402

PRIV = re.compile(r"^\s*/\*.*?\*/\s+(mtc0|mfc0|dmtc0|dmfc0|eret|cache|ll|sc|lld|scd|tlbr|tlbwi|tlbwr|tlbp|sync|syscall)\s", re.M)
KREG = re.compile(r"\$k[01]\b")
FPCSR = re.compile(r"^\s*/\*.*?\*/\s+(cfc1|ctc1)\s+.*\$(?:31|fcr31)", re.M)
UNALIGNED = re.compile(r"^\s*/\*.*?\*/\s+(lwl|lwr|swl|swr|ldl|ldr|sdl|sdr)\s", re.M)
CALL = re.compile(r"^\s*/\*.*?\*/\s+jal\s", re.M)
LOOP = re.compile(r"^\s*/\*.*?\*/\s+b\w*\s+.*\.L", re.M)


def classify(text, size):
    """(verdict, evidence list)."""
    ev = sorted({m.group(1) for m in PRIV.finditer(text)})
    if KREG.search(text):
        ev.append("$k0/$k1")
    if FPCSR.search(text) and not CALL.search(text) and size <= 0x20:
        ev.append("fcr31 access")
    if ev:
        return "asm_only", ev
    odd = []
    if UNALIGNED.search(text):
        odd.append("lwl/lwr/swl/swr")
    if size <= 0x20 and not CALL.search(text):
        odd.append("tiny leaf")
    return "c-candidate", odd


def have_of(seg):
    f = ROOT / "config" / seg / "asm_only.txt"
    return set(f.read_text().split()) if f.exists() else set()


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    apply = "--apply" in sys.argv
    found = {}
    for seg in hard_scan.segments(args):
        asm = hard_scan.ROOT / (f"asm/overlays/{seg[3:]}/text.s" if seg.startswith("ovl") else f"asm/{seg}/text.s")
        bodies = {c.split(",")[0].split()[1]: c for c in re.split(r"(?=^nonmatching )", asm.read_text(), flags=re.M)[1:]}
        listed = ROOT / "config" / seg / "asm_only.txt"
        have = set(listed.read_text().split()) if listed.exists() else set()
        for fn, size, cats in hard_scan.scan(seg):
            verdict, ev = classify(bodies[fn], size)
            found.setdefault(seg, []).append((fn, size, verdict, ev, "hand" in cats))   # last: already outside the C todo (marked or listed)
    for seg, rows in found.items():
        solid = [r for r in rows if r[2] == "asm_only"]
        new = [r for r in solid if not r[4]]
        odd = [r for r in rows if r[2] == "c-candidate" and r[3]]
        listed_only = [r for r in rows if r[4] and r[2] != "asm_only" and r[0] in have_of(seg)]
        if not args or not seg.startswith("ovl") or solid or odd:
            print(f"{seg}: {len(rows)} unmatched, {len(solid)} asm_only by instruction evidence ({len(new)} not in asm_only.txt), "
                  f"{len(listed_only)} in asm_only.txt without instruction evidence, {len(odd)} odd-looking C candidates")
        for fn, size, v, ev, inl in solid:
            if len(found) <= 3:
                print(f"  asm_only {fn} {size:#x} {','.join(ev)}{'' if inl else '  (not in asm_only.txt)'}")
        for fn, size, v, ev, inl in listed_only:
            if len(found) <= 3:
                print(f"  listed-only {fn} {size:#x} (asm_only.txt, no privileged instruction: check by hand)")
        if apply and not seg.startswith("ovl") and new:
            path = ROOT / "config" / seg / "asm_only.txt"
            old = path.read_text() if path.exists() else ""
            path.write_text(old + ("" if old.endswith("\n") or not old else "\n") + "".join(f"{r[0]}\n" for r in sorted(new)))
            print(f"  {path.relative_to(ROOT)}: +{len(new)}")


if __name__ == "__main__":
    main()
