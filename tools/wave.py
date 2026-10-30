#!/usr/bin/env python3
"""Prepare a wave of functions for the AI agents, and list what is worth trying next.
usage: wave.py <seg> <count> [chunks=8] [--switch] [--max-size 0x..]
Picks the `count` smallest functions that have no C yet (no src/<seg>/<fn>.c, no wip draft, not hand-written
assembly, not a known unmatched-by-construction function), splits them into `chunks` lists (round robin, so every
agent gets a mix of sizes) and writes build/wave/<seg>.chunkNN (one function per line) plus build/wave/<seg>.all.
--switch picks only functions with a jump table, the default skips them.
After the agents are done run `tools/wave_finish.sh` (names, full verification, style)."""
import re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import srcpath  # noqa: E402
# instructions IDO never emits: a function using one was written in assembly (`addi` traps on overflow, IDO uses `addiu`)
HAND_WRITTEN = re.compile(r"\b(mtc0|mfc0|cache|cfc1|ctc1|eret|tlbwi|tlbr|tlbp|sync|addi)\b")


def functions(seg: str):
    """(name, size, uses_jump_table, hand_written_instruction) for every function of the splat assembly."""
    text = (ROOT / "asm" / seg / "text.s").read_text()
    out = []
    for block in re.split(r"(?=^nonmatching )", text, flags=re.M)[1:]:
        m = re.match(r"nonmatching (\w+), (0x[0-9A-Fa-f]+)", block)
        if not m or not block.lstrip().split("\n", 1)[1].lstrip().startswith("glabel"):
            continue  # data labels inside the text region
        out.append((m.group(1), int(m.group(2), 16), "jtbl_" in block, bool(HAND_WRITTEN.search(block))))
    return out


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    seg, count = args[0], int(args[1])
    chunks = int(args[2]) if len(args) > 2 else 8
    want_switch = "--switch" in sys.argv
    max_size = int(sys.argv[sys.argv.index("--max-size") + 1], 16) if "--max-size" in sys.argv else 1 << 30
    asm_only = set((ROOT / "config" / f"{seg}.asm_only.txt").read_text().split()) \
        if (ROOT / "config" / f"{seg}.asm_only.txt").exists() else set()
    have = {p.stem for p in srcpath.files(seg)} | {p.stem for p in (ROOT / "src" / seg / "wip").glob("func_*.c")}
    todo = sorted((size, n) for n, size, jt, hw in functions(seg)
                  if n not in have and n not in asm_only and not hw and jt == want_switch and size <= max_size)[:count]
    out = ROOT / "build" / "wave"
    out.mkdir(parents=True, exist_ok=True)
    for old in out.glob(f"{seg}.*"):
        old.unlink()
    (out / f"{seg}.all").write_text("".join(f"{n}\n" for _, n in todo))
    for i in range(chunks):
        (out / f"{seg}.chunk{i:02d}").write_text("".join(f"{n}\n" for _, n in todo[i::chunks]))
    print(f"{seg}: {len(todo)} functions, sizes {todo[0][0]:#x}..{todo[-1][0]:#x}, {chunks} chunks in {out}" if todo else f"{seg}: nothing to do")


if __name__ == "__main__":
    main()
