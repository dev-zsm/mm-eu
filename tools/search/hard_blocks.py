#!/usr/bin/env python3
"""Match a large function piece by piece: compare basic blocks of the ROM with ours and print the FIRST block that differs, with context.
Run in WSL (venv).  usage: hard_blocks.py <seg> <fn> <file.c> [--all] [--context N]

Unlike `tools/mm diff`, an inserted or missing instruction does not shift everything after it: the two instruction streams are aligned first
(on opcode and registers; immediates, branch offsets and relocations are compared after the alignment), then each ROM basic block is judged:
  ok      every instruction of the block has its equal in ours, and the branches go to the aligned blocks
  DIFF    something in it differs (the lines are printed, `!!` = different, `<` = only in the ROM, `>` = only in ours)
Matching a 400-instruction function: write the first part of the C, end it with a call to an extern `STUB();` and a `return`, run this tool:
the first differing block is the first place where the code you wrote is not the ROM's (blocks after the stub are expected to differ and are
listed as `missing`). Extend the C, run again. The tail (epilogue) of a stubbed function differs by design: only the first DIFF counts.
--all prints every differing block; --context N sets the number of equal lines shown before the first difference (default 4)."""
import difflib, re, struct, sys, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import match  # noqa: E402


def dis(code: bytes) -> list:
    with tempfile.TemporaryDirectory() as d:
        Path(d, "b").write_bytes(code)
        out = match.run("mips-linux-gnu-objdump", "-b", "binary", "-m", "mips:4300", "-EB", "-D", "-z", "-M", "no-aliases", d + "/b")   # -z: no `...` for runs of nops
    return [l.split("\t", 2)[-1] if "\t" in l else l for l in out.splitlines() if l[:1] == " " and ":" in l]


def kind(w):
    """'branch' (16-bit offset), 'jump' (26-bit target), 'jr' or 'plain'."""
    op = w >> 26
    if op in (1, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17) or (op == 0x11 and (w >> 21) & 31 == 8):
        return "branch"
    if op in (2, 3):
        return "jump"
    if op == 0 and w & 0x3F in (8, 9):
        return "jr"
    return "plain"


def key(w):
    """What the alignment compares: opcode and registers; no immediate, no offset, no target."""
    k = kind(w)
    if k == "jump":
        return w >> 26
    op = w >> 26
    if k == "branch" or (op >= 8 and op != 0x11 or op == 1):   # I-type: opcode, rs, rt
        return w >> 16
    return w


def leaders(words):
    """Indices that start a basic block."""
    lead = {0}
    for i, w in enumerate(words):
        k = kind(w)
        if k == "branch":
            off = struct.unpack(">h", struct.pack(">H", w & 0xFFFF))[0]
            t = i + 1 + off
            if 0 <= t < len(words):
                lead.add(t)
            if i + 2 < len(words):
                lead.add(i + 2)
        elif k in ("jump", "jr") and (w >> 26 == 2 or k == "jr" and w & 0x3F == 8) and i + 2 < len(words):
            lead.add(i + 2)
    return sorted(lead)


def target(words, i):
    w = words[i]
    return i + 1 + struct.unpack(">h", struct.pack(">H", w & 0xFFFF))[0]


def compare(want, got, masks):
    """(pairs {rom index: ours index}, exact {rom index: bool}, lines for display)."""
    a = list(struct.unpack(f">{len(want) // 4}I", want))
    b = list(struct.unpack(f">{len(got) // 4}I", got))
    sm = difflib.SequenceMatcher(None, [key(x) for x in a], [key(x) for x in b], autojunk=False)
    pairs, ops = {}, sm.get_opcodes()
    for tag, i1, i2, j1, j2 in ops:
        if tag == "equal":
            for d in range(i2 - i1):
                pairs[i1 + d] = j1 + d
    exact = {}
    for i, j in pairs.items():
        x, y = a[i], b[j]
        m = masks.get(j * 4)
        if kind(x) == "branch":
            x = x & 0xFFFF0000
            y = y & 0xFFFF0000
        elif kind(x) == "jump" and x >> 26 == 3:
            x, y = x >> 26, y >> 26   # jal: the target is a relocation or checked by the full build
        elif m:
            x, y = x & ~m, y & ~m
        exact[i] = x == y
    return a, b, pairs, exact, ops


def main():
    args = [x for x in sys.argv[1:] if not x.startswith("--")]
    show_all = "--all" in sys.argv
    ctx = int(sys.argv[sys.argv.index("--context") + 1]) if "--context" in sys.argv else 4
    if "--context" in sys.argv:
        args.remove(sys.argv[sys.argv.index("--context") + 1])
    seg, name, cfile = args[0], args[1], Path(args[2])
    want, _ = match.original(seg, name)
    got, masks = match.compiled(cfile, name, match.file_flags(cfile), len(want))
    while len(got) > 4 and not any(got[-4:]) and len(got) > len(want):   # IDO pads .text to 16 bytes
        got = got[:-4]
    a, b, pairs, exact, ops = compare(want, got, masks)
    w, g = dis(want), dis(got)
    inv = {j: i for i, j in pairs.items()}
    lead = leaders(a)
    ends = lead[1:] + [len(a)]
    print(f"{name}: ROM {len(a)} instructions, ours {len(b)}; {sum(exact.values())} equal after alignment")
    bad_blocks = []
    for n, (s, e) in enumerate(zip(lead, ends)):
        problems = []
        for i in range(s, e):
            if i not in pairs:
                problems.append((i, "missing"))
            elif not exact[i]:
                problems.append((i, "differs"))
            elif kind(a[i]) == "branch":
                t_rom, t_ours = target(a, i), target(b, pairs[i])
                if t_rom in pairs and pairs[t_rom] != t_ours:
                    problems.append((i, "branch goes elsewhere"))
        if problems:
            bad_blocks.append((n, s, e, problems))
    if not bad_blocks and len(a) == len(b):
        print("all blocks equal: the function should MATCH")
        return
    print(f"{len(lead)} blocks; {len(bad_blocks)} differ: " + " ".join(f"#{n}@{s * 4:#x}" for n, s, e, _ in bad_blocks[:12]))
    for n, s, e, problems in (bad_blocks if show_all else bad_blocks[:1]):
        print(f"\n-- block #{n}: ROM {s * 4:#x}..{e * 4:#x}  ({', '.join(f'{why} at {i * 4:#x}' for i, why in problems[:4])})")
        lo = max(0, s - ctx)
        # the ROM lines of the block, with the aligned line of ours; lines of ours that are in no pair and fall inside the block are shown as '>'
        shown = set()
        for i in range(lo, e):
            j = pairs.get(i)
            if j is None:
                print(f"{i * 4:04x} <  {w[i]:<44}|")
            else:
                if j in shown:
                    continue
                mark = "  " if exact[i] else "!!"
                print(f"{i * 4:04x} {mark} {w[i]:<44}| {g[j]}")
            nxt = pairs.get(i + 1)
            prev = pairs.get(i)
            if prev is not None and nxt is not None:
                for jj in range(prev + 1, nxt):   # lines of ours between two aligned lines
                    print(f"     >  {'':<44}| {g[jj]}")
            elif prev is not None and i + 1 >= e:
                pass
        extra = [j for j in range(len(b)) if j not in inv]
        if extra and n == bad_blocks[0][0]:
            near = [j for j in extra if pairs.get(s) is not None and pairs[s] - 8 <= j <= pairs[s] + (e - s) + 8]
            if near:
                print("  only in ours near here: " + ", ".join(f"{j * 4:#x}: {g[j]}" for j in near[:6]))
    if len(b) < len(a):
        print(f"\nours ends {len(a) - len(b)} instructions short of the ROM")


if __name__ == "__main__":
    main()
