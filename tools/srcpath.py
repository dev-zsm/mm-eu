"""Where the verified C of a function lives. `code` is split into one folder per original source file
(config/code.layout.txt, made by tools/layout.py), e.g. src/code/Camera/func_800xxxxx.c, so that no folder has more than
1000 files (GitHub lists at most 1000 per folder); `boot` stays flat.
New files may still be written flat (agents, permuter): tools/srcsort.py files them into their folder."""
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BUCKETED = {"code"}
_layout = {}


def _folders(seg):
    if seg not in _layout:
        f = ROOT / "config" / f"{seg}.layout.txt"
        _layout[seg] = dict(l.split() for l in f.read_text().splitlines()) if f.exists() else {}
    return _layout[seg]


def bucket(seg, fn):
    return _folders(seg)[fn]


def path(seg, fn):
    """Existing file of `fn` (flat or in its folder); else where it belongs."""
    flat = ROOT / "src" / seg / f"{fn}.c"
    if flat.exists() or seg not in BUCKETED or fn not in _folders(seg):  # data symbols have no folder
        return flat
    return ROOT / "src" / seg / bucket(seg, fn) / f"{fn}.c"


def files(seg):
    """Every verified C file of the segment (not wip), sorted by name."""
    d = ROOT / "src" / seg
    found = list(d.glob("func_*.c")) + [p for p in d.glob("*/func_*.c") if p.parent.name != "wip"]
    return sorted(found, key=lambda p: p.name)
