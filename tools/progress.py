#!/usr/bin/env python3
"""Progress report for a segment: how much of the original code is C verified against the ROM.
usage: progress.py [boot code ...]   (writes docs/PROGRESS.md and prints it)"""
import re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import names  # noqa: E402


def segment(seg: str) -> dict:
    text = (ROOT / "asm" / seg / "text.s").read_text()
    funcs = []  # (name, size, handwritten)
    for b in re.split(r"(?=^nonmatching )", text, flags=re.M)[1:]:
        m = re.match(r"nonmatching (\w+), (0x[0-9A-Fa-f]+)", b)
        if not m or not b.lstrip().split("\n", 1)[1].lstrip().startswith("glabel"):
            continue  # data labels inside the text region
        pre = text[:text.index(b)][-120:]
        funcs.append((m.group(1), int(m.group(2), 16), "Handwritten function" in pre))
    asm_only = set((ROOT / "config" / f"{seg}.asm_only.txt").read_text().split()) \
        if (ROOT / "config" / f"{seg}.asm_only.txt").exists() else set()
    src = {p.stem for p in (ROOT / "src" / seg).glob("func_*.c")}
    wip = {p.stem for p in (ROOT / "src" / seg / "wip").glob("func_*.c")} if (ROOT / "src" / seg / "wip").exists() else set()
    named = names.load(seg)
    c = [f for f in funcs if f[0] in src]
    hand = [f for f in funcs if f[2] or f[0] in asm_only]
    return {
        "total": len(funcs), "bytes": sum(f[1] for f in funcs),
        "c": len(c), "c_bytes": sum(f[1] for f in c),
        "asm_original": len(hand), "wip": len(wip & {f[0] for f in funcs}),
        "todo": len(funcs) - len(c) - len(hand),
        "named": len([f for f in funcs if f[0] in named]),
    }


def main():
    segs = sys.argv[1:] or ["boot", "code"]
    rows = ["| Segment | Fonctions en C vérifié | Octets en C | Assembleur d'origine | Essais (wip) | Reste | Nommées |",
            "|---|---|---|---|---|---|---|"]
    for s in segs:
        r = segment(s)
        pct = 100 * r["c"] / max(1, r["total"] - r["asm_original"])
        pcb = 100 * r["c_bytes"] / max(1, r["bytes"])
        rows.append(f"| `{s}` | {r['c']} / {r['total'] - r['asm_original']} ({pct:.1f} %) | {r['c_bytes']:#x} / {r['bytes']:#x} ({pcb:.1f} %) "
                    f"| {r['asm_original']} | {r['wip']} | {r['todo']} | {r['named']} |")
    out = ("# Progression\n\nGénéré par `tools/progress.py`. « Fonctions en C vérifié » : compilées avec IDO 7.1 en octets identiques à la ROM.\n"
           "« Assembleur d'origine » : fonctions écrites à la main ou impossibles en C (non comptées dans le dénominateur).\n\n" + "\n".join(rows) + "\n")
    (ROOT / "docs").mkdir(exist_ok=True)
    (ROOT / "docs" / "PROGRESS.md").write_text(out)
    print(out)


if __name__ == "__main__":
    main()
