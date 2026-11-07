#!/usr/bin/env python3
"""Progress report for a segment: how much of the original code is C verified against the ROM.
usage: progress.py [boot code ...]   (writes docs/PROGRESS.md, refreshes the progress bars in README.md, prints the report)"""
import collections, datetime, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
# a function with a professional signature includes a shared header of include/ (not only the base types or the draft macros)
TYPED = re.compile(r'^#include "(?!types\.h|m2c_compat\.h|m2c_macros\.h)[^"]+\.h"', re.M)
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import match  # noqa: E402
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
    asm_only = set((ROOT / "config" / seg / "asm_only.txt").read_text().split()) \
        if (ROOT / "config" / seg / "asm_only.txt").exists() else set()
    src = {p.stem for p in srcpath.files(seg)}
    wip = {p.stem for p in (ROOT / "src" / seg / "wip").glob("func_*.c")} if (ROOT / "src" / seg / "wip").exists() else set()
    named = names.load(seg)
    c = [f for f in funcs if f[0] in src]
    hand = [f for f in funcs if f[2] or f[0] in asm_only]
    return {
        "total": len(funcs), "bytes": sum(f[1] for f in funcs),
        "c": len(c), "c_bytes": sum(f[1] for f in c),
        "drafts": sum(1 for n in src if "m2c_compat.h" in srcpath.path(seg, n).read_text()),
        "typed": sum(1 for n in src if TYPED.search(srcpath.path(seg, n).read_text())),
        "asm_original": len(hand), "wip": len(wip & {f[0] for f in funcs}),
        "todo": len(funcs) - len(c) - len(hand),
        "named": len([f for f in funcs if f[0] in named]),
    }


def overlays() -> tuple:
    """(number of overlays, bytes of code) from config/overlays/list.txt (tools/split/overlays.py); (0, 0) when it is missing."""
    f = ROOT / "config" / "overlays" / "list.txt"
    rows = [l.split() for l in f.read_text().splitlines()] if f.exists() else []
    return len(rows), sum(int(r[2], 16) for r in rows)


def overlay_segment() -> dict:
    """Same numbers as segment() for all the overlays together: functions of asm/overlays/*/text.s, C files of src/overlays/*/."""
    funcs = {}  # (overlay, function) -> size
    for t in sorted((ROOT / "asm" / "overlays").glob("*/text.s")):
        for m in re.finditer(r"^nonmatching (\w+), (0x[0-9A-Fa-f]+)", t.read_text(), re.M):
            funcs[(t.parent.name, m.group(1))] = int(m.group(2), 16)
    files = list((ROOT / "src" / "overlays").glob("*/func_*.c"))
    done = {(p.parent.name, p.stem) for p in files}
    wip = {(p.parent.parent.name, p.stem) for p in (ROOT / "src" / "overlays").glob("*/wip/func_*.c")}
    c = [k for k in funcs if k in done]
    return {"total": len(funcs), "bytes": sum(funcs.values()), "c": len(c), "c_bytes": sum(funcs[k] for k in c),
            "drafts": sum("m2c_compat.h" in p.read_text() for p in files),
            "typed": sum(bool(TYPED.search(p.read_text())) for p in files),
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
        pct = 100 * r["c"] / max(1, denom)
        lines.append(f"{s:<8} {bar(pct)} {pct:5.1f} %  ({r['c']} / {denom})")
    block = (f"{a}\nMatching C verified byte-for-byte against the ROM (refreshed by `make progress`, "
             f"last update {datetime.date.today()}):\n\n```\n" + "\n".join(lines) + f"\n```\n{b}")
    head, rest = text.split(a, 1)
    readme.write_text(head + block + rest.split(b, 1)[1], encoding="utf-8")


def asm_note(segs):
    """Functions with verified C that the rebuilt segment still takes from the assembly (their constant pool is not the ROM's):
    tools/lib/build_seg.py writes the list. They are counted as C above, so say how many there are."""
    parts = []
    for s in segs:
        f = ROOT / "build" / s / "built_from_asm.txt"
        if f.exists() and f.read_text().split():
            parts.append(f"`{s}` {len(f.read_text().split())}")
    return ("Verified C that the rebuilt segment still takes from the assembly because its constant pool is not the ROM's "
            "(counted as C above): " + ", ".join(parts) + ".\n\n") if parts else ""


def overlay_index():
    """docs/OVERLAYS_INDEX.md: every overlay with its name, its functions in C and the ones that have a name."""
    cfg = ROOT / "config" / "overlays"
    actors = {l.split()[0]: l.split()[1] for l in (cfg / "actors.txt").read_text().splitlines() if l.strip() and not l.startswith("#")} \
        if (cfg / "actors.txt").exists() else {}
    named = collections.Counter(l.split()[0] for l in (cfg / "names.txt").read_text().splitlines() if l.strip() and not l.startswith("#")) \
        if (cfg / "names.txt").exists() else collections.Counter()
    rows = ["| Overlay | Name | Functions | In C | Named |", "|---|---|---|---|---|"]
    for line in (cfg / "list.txt").read_text().splitlines():
        if not line.strip():
            continue
        idx = line.split()[0]
        total = len(match._sizes(f"ovl{idx}")) if (ROOT / "asm" / "overlays" / idx / "text.s").exists() else 0
        d = ROOT / "src" / "overlays" / idx
        done = len(list(d.glob("func_*.c"))) if d.exists() else 0
        rows.append(f"| `{idx}` | {actors.get(idx, '')} | {total} | {done} | {named.get(idx, 0)} |")
    head = ("# Overlays\n\nGenerated by `tools/check/progress.py`. The name of an overlay and of its functions come from the reference "
            "(`config/overlays/actors.txt`, `config/overlays/names.txt`, written by `tools/search/ref_import.py run names`) and only where the "
            "bytes of its functions match.\n\n")
    (ROOT / "docs" / "OVERLAYS_INDEX.md").write_text(head + "\n".join(rows) + "\n", encoding="utf-8")


def main():
    segs = sys.argv[1:] or ["boot", "code"]
    rows = ["| Segment | C functions (verified) | of which drafts to clean up | Typed signatures | C bytes | Original assembly | Attempts (wip) | Remaining | Named |",
            "|---|---|---|---|---|---|---|---|---|"]
    results = {}
    for s in segs:
        r = segment(s)
        results[s] = r
        pct = 100 * r["c"] / max(1, r["total"] - r["asm_original"])
        pcb = 100 * r["c_bytes"] / max(1, r["bytes"])
        rows.append(f"| `{s}` | {r['c']} / {r['total'] - r['asm_original']} ({pct:.1f} %) | {r['drafts']} | {r['typed']} / {r['c']} | {r['c_bytes']:#x} / {r['bytes']:#x} ({pcb:.1f} %) "
                    f"| {r['asm_original']} | {r['wip']} | {r['todo']} | {r['named']} |")
    if "boot" in segs and "code" in segs:  # the overlays are counted with the full run only
        r = results["overlays"] = overlay_segment()
        pct = 100 * r["c"] / max(1, r["total"])
        rows.append(f"| `overlays` | {r['c']} / {r['total']} ({pct:.1f} %) | {r['drafts']} | {r['typed']} / {r['c']} | {r['c_bytes']:#x} / {r['bytes']:#x} ({100 * r['c_bytes'] / max(1, r['bytes']):.1f} %) "
                    f"| 0 | {r['wip']} | {r['todo']} | 0 |")
    out = ("# Progress\n\nGenerated by `tools/check/progress.py` (`make progress`).\n\n"
           "* **C functions (verified)**: compiled with IDO (7.1, or 5.3 for part of libultra) to bytes identical to the ROM.\n"
           "* **Drafts to clean up**: verified, but still written with raw field offsets (`M2C_FIELD`) from the automatic draft; they become real struct accesses once the types are known.\n"
           "* **Typed signatures**: verified functions that use the shared headers of `include/` (real types and parameter names, one prototype) instead of local placeholder types; see the rule in [CONTRIBUTING.md](CONTRIBUTING.md#code-style).\n"
           "* **C bytes**: share of the segment's code bytes covered by verified C.\n"
           "* **Original assembly**: hand-written in the original game or impossible in C; not counted in the denominator.\n"
           "* **Attempts (wip)**: unfinished drafts in `src/<segment>/wip/`.\n\n" + "\n".join(rows) + "\n\n"
           f"`overlays` adds up the {overlays()[0]} overlays (actors, scenes, menus) found by `tools/split/overlays.py`; their C is verified function by function: "
           "the bytes with the relocated fields masked, then the address each call or data reference would link to, against the ROM's "
           "(the overlays are not rebuilt whole yet, see [ROADMAP.md](ROADMAP.md), section 3).\n\n"
           + asm_note(segs) +
           "Naming, file layout and readability work is planned for after all the C matches: see [ROADMAP.md](ROADMAP.md).\n")
    (ROOT / "docs").mkdir(exist_ok=True)
    (ROOT / "docs" / "PROGRESS.md").write_text(out, encoding="utf-8")
    if {"boot", "code"} <= set(results):  # a partial run (one segment) must not rewrite the README bars
        update_readme(results)
        overlay_index()
    print(out)


if __name__ == "__main__":
    main()
