#!/usr/bin/env python3
"""Write the m2c draft of every unmatched overlay function of a range to build/auto_drafts/<seg>/<fn>.c (the place close.py sweep reads).
usage: draft_all.py ovlLO-ovlHI [max_size_hex=0x400] [jobs=3]      (run in WSL, venv active)
A function with a verified file, a wip file or a draft already is skipped. close.py sweep then measures and closes them."""
import re, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import hard_scan  # noqa: E402
import permute_list  # noqa: E402
import match  # noqa: E402
import hard_jt  # noqa: E402


def make(job):
    seg, fn, asm, jt = job
    if not jt:
        return permute_list.make_draft(seg, fn, asm)
    try:
        text, _ = hard_jt.draft(seg, fn)   # m2c wants the jump table: the draft of a switch
    except Exception:
        return False
    if not text:
        return False
    out = ROOT / "build/auto_drafts" / seg / f"{fn}.c"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text('#include "types.h"\n#include "m2c_macros.h"\n\n' + text.replace("void *", "u8 *"))
    return True


def main():
    m = re.fullmatch(r"(?:ovl)?(\d{4})-(?:ovl)?(\d{4})", sys.argv[1])
    lo, hi = int(m.group(1)), int(m.group(2))
    max_size = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x400
    jobs = int(sys.argv[3]) if len(sys.argv) > 3 else 3
    todo = []
    for seg in hard_scan.segments(["overlays"]):
        if not lo <= int(seg[3:]) <= hi:
            continue
        text = match.asm_file(seg).read_text()
        head = text[:text.index("nonmatching ")]
        chunks = {c.split(",")[0].split()[1]: c for c in re.split(r"(?=^nonmatching )", text, flags=re.M)[1:]}
        for fn, size, cats in hard_scan.scan(seg):
            d = ROOT / "build/auto_drafts" / seg / f"{fn}.c"
            if size <= max_size and not d.exists() and not (hard_scan.srcpath.overlay_dir(seg[3:]) / "wip" / f"{fn}.c").exists():
                todo.append((seg, fn, head + chunks[fn], "jtbl" in cats))
    print(len(todo), "to draft", flush=True)
    with ThreadPoolExecutor(jobs) as ex:
        ok = sum(ex.map(make, todo))
    print(ok, "drafts written")


if __name__ == "__main__":
    main()
