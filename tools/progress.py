#!/usr/bin/env python3
"""Progress report for a segment: how much of the original code is C verified against the ROM.
usage: progress.py [boot code ...]   (writes docs/PROGRESS.md, refreshes the progress bars in README.md, prints the report)"""
import datetime, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import names  # noqa: E402
import srcpath  # noqa: E402


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
    src = {p.stem for p in srcpath.files(seg)}
    wip = {p.stem for p in (ROOT / "src" / seg / "wip").glob("func_*.c")} if (ROOT / "src" / seg / "wip").exists() else set()
    named = names.load(seg)
    c = [f for f in funcs if f[0] in src]
    hand = [f for f in funcs if f[2] or f[0] in asm_only]
    return {
        "total": len(funcs), "bytes": sum(f[1] for f in funcs),
        "c": len(c), "c_bytes": sum(f[1] for f in c),
        "drafts": sum(1 for n in src if "m2c_compat.h" in srcpath.path(seg, n).read_text()), "asm_original": len(hand), "wip": len(wip & {f[0] for f in funcs}),
        "todo": len(funcs) - len(c) - len(hand),
        "named": len([f for f in funcs if f[0] in named]),
    }


def overlays() -> tuple:
    """(number of overlays, bytes of code) from config/overlays.txt (tools/overlays.py); (0, 0) when it is missing."""
    f = ROOT / "config" / "overlays.txt"
    rows = [l.split() for l in f.read_text().splitlines()] if f.exists() else []
    return len(rows), sum(int(r[2], 16) for r in rows)


def overlay_segment() -> dict:
    """Same numbers as segment() for all the overlays together: functions of asm/overlays/*/text.s, C files of src/overlays/*/."""
    funcs = {}  # (overlay, function) -> size
    for t in sorted((ROOT / "asm" / "overlays").glob("*/text.s")):
        for m in re.finditer(r"^nonmatching (\w+), (0x[0-9A-Fa-f]+)", t.read_text(), re.M):
            funcs[(t.parent.name, m.group(1))] = int(m.group(2), 16)
    done = {(p.parent.name, p.stem) for p in (ROOT / "src" / "overlays").glob("*/func_*.c")}
    wip = {(p.parent.parent.name, p.stem) for p in (ROOT / "src" / "overlays").glob("*/wip/func_*.c")}
    c = [k for k in funcs if k in done]
    return {"total": len(funcs), "bytes": sum(funcs.values()), "c": len(c), "c_bytes": sum(funcs[k] for k in c), "drafts": 0,
            "asm_original": 0, "wip": len(wip & set(funcs)), "todo": len(funcs) - len(c), "named": 0}


def bar(pct: float, width: int = 30) -> str:
    n = round(width * pct / 100)
    return "█" * n + "░" * (width - n)


def update_readme(results: dict):
    """Rewrite the block between the progress markers of README.md (no-op when the markers are missing)."""
    readme = ROOT / "README.md"
    text = readme.read_text(encoding="utf-8")
    a, b = "<!-- progress:start -->", "<!-- progress:end -->"
    if a not in text or b not in text:
        return
    lines = []
    for s, r in results.items():
        denom = r["total"] - r["asm_original"]
        for label, pct, extra in (("functions", 100 * r["c"] / max(1, denom), f"{r['c']} / {denom}"),
                                  ("code size", 100 * r["c_bytes"] / max(1, r["bytes"]), f"{r['c_bytes']:#x} / {r['bytes']:#x} bytes")):
            lines.append(f"{s:<5} {label:<9} {bar(pct)} {pct:5.1f} %  ({extra})")
    block = (f"{a}\nMatching C verified byte-for-byte against the ROM (refreshed by `make progress`, "
             f"last update {datetime.date.today()}):\n\n```\n" + "\n".join(lines) + f"\n```\n{b}")
    head, rest = text.split(a, 1)
    readme.write_text(head + block + rest.split(b, 1)[1], encoding="utf-8")


def main():
    segs = sys.argv[1:] or ["boot", "code"]
    rows = ["| Segment | C functions (verified) | of which drafts to clean up | C bytes | Original assembly | Attempts (wip) | Remaining | Named |",
            "|---|---|---|---|---|---|---|---|"]
    results = {}
    for s in segs:
        r = segment(s)
        results[s] = r
        pct = 100 * r["c"] / max(1, r["total"] - r["asm_original"])
        pcb = 100 * r["c_bytes"] / max(1, r["bytes"])
        rows.append(f"| `{s}` | {r['c']} / {r['total'] - r['asm_original']} ({pct:.1f} %) | {r['drafts']} | {r['c_bytes']:#x} / {r['bytes']:#x} ({pcb:.1f} %) "
                    f"| {r['asm_original']} | {r['wip']} | {r['todo']} | {r['named']} |")
    if "boot" in segs and "code" in segs:  # the overlays are counted with the full run only
        r = results["overlays"] = overlay_segment()
        pct = 100 * r["c"] / max(1, r["total"])
        rows.append(f"| `overlays` | {r['c']} / {r['total']} ({pct:.1f} %) | 0 | {r['c_bytes']:#x} / {r['bytes']:#x} ({100 * r['c_bytes'] / max(1, r['bytes']):.1f} %) "
                    f"| 0 | {r['wip']} | {r['todo']} | 0 |")
    out = ("# Progress\n\nGenerated by `tools/progress.py` (`make progress`).\n\n"
           "* **C functions (verified)**: compiled with IDO 7.1 to bytes identical to the ROM.\n"
           "* **Drafts to clean up**: verified, but still written with raw field offsets (`M2C_FIELD`) from the automatic draft; they become real struct accesses once the types are known.\n"
           "* **C bytes**: share of the segment's code bytes covered by verified C.\n"
           "* **Original assembly**: hand-written in the original game or impossible in C; not counted in the denominator.\n"
           "* **Attempts (wip)**: unfinished drafts in `src/<segment>/wip/`.\n\n" + "\n".join(rows) + "\n\n"
           f"`overlays` adds up the {overlays()[0]} overlays (actors, scenes, menus) found by `tools/overlays.py`; their C is verified function by function "
           "until the overlay build exists (see [ROADMAP.md](ROADMAP.md), section 3).\n\n"
           "Naming, file layout and readability work is planned for after all the C matches: see [ROADMAP.md](ROADMAP.md).\n")
    (ROOT / "docs").mkdir(exist_ok=True)
    (ROOT / "docs" / "PROGRESS.md").write_text(out, encoding="utf-8")
    if {"boot", "code"} <= set(results):  # a partial run (one segment) must not rewrite the README bars
        update_readme(results)
    print(out)


if __name__ == "__main__":
    main()
