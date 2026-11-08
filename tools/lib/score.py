#!/usr/bin/env python3
"""Near-miss score of a compiled function against the ROM, on lists of 32-bit instruction words (already relocation-masked,
see match.mask). Pure functions, shared by the match server (tools/fast) and the searches that rank candidates.

score(want, got) returns
  diff      instructions that differ position by position, plus the words one side has more (what match.py counts)
  size      difference of length in words (ours - ROM)
  reg       differing instructions that are equal once the register fields are ignored (a register allocation difference)
  moved     the other differing instructions whose word the ROM has elsewhere among the differing ones (an ordering difference)
  hard      the rest (a different instruction)
  edit      instructions outside the longest common subsequence (an insertion or a deletion costs one, not a whole shifted tail);
            None for a function too large to align
  score     min(hard + size + 0.5 * moved + 0.25 * reg, edit): 0 is a match, lower is closer
  first     byte offsets of the first differing instructions"""
import collections, difflib


def strip_regs(w: int) -> int:
    """The instruction word without its register fields (the shift amount and the function field stay)."""
    op = w >> 26
    if op == 0:
        return w & ~0x03FFF800            # SPECIAL: rs rt rd
    if op in (1, 2, 3):
        return w                          # REGIMM, j, jal: no register to ignore (rt of REGIMM selects the instruction)
    if op == 0x11:                        # COP1: mfc1/mtc1 name rt and fs, arithmetic names ft fs fd, bc1 none
        fmt = (w >> 21) & 31
        return w & ~0x001FFFC0 if fmt >= 16 else w & ~0x001FF800 if fmt < 8 else w
    return w & ~0x03FF0000                # I-type: rs rt


def score(want: list, got: list, first: int = 8) -> dict:
    n = min(len(want), len(got))
    size = len(got) - len(want)
    pos = [i for i in range(n) if want[i] != got[i]]
    reg = [i for i in pos if strip_regs(want[i]) == strip_regs(got[i])]
    regs = set(reg)
    rest = [i for i in pos if i not in regs]
    left = collections.Counter(want[i] for i in rest)
    moved = 0
    for i in rest:
        if left[got[i]] > 0:
            left[got[i]] -= 1
            moved += 1
    hard = len(rest) - moved
    fine = hard + abs(size) + 0.5 * moved + 0.25 * len(reg)
    edit = None
    if not pos and not size:
        edit = 0
    elif len(want) * len(got) <= 250_000:
        aligned = sum(b.size for b in difflib.SequenceMatcher(None, want, got, autojunk=False).get_matching_blocks())
        edit = max(len(want), len(got)) - aligned
    return {"diff": len(pos) + abs(size), "size": size, "reg": len(reg), "moved": moved, "hard": hard, "edit": edit,
            "score": fine if edit is None else min(fine, edit), "first": [i * 4 for i in pos[:first]]}
