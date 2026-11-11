#!/usr/bin/env python3
"""Move to wip/ every C function that does not compile or does not match the ROM, with the headers as they are now.
Run in WSL.  usage: quarantine.py <boot|code|overlays> [--max N]
1. tools/check/verify_src.py: a file that no longer compiles (a header that changed under it), or whose bytes or call targets differ, goes to
   src/<seg>/wip/ (an overlay: the wip/ of its folder). Only those functions: the rest of the segment keeps its C.
   --max N: when more than N files fail, nothing is moved and the exit status is 3 (a header broke the segment: the caller drops the
   step that wrote it instead of losing hundreds of functions).
2. boot and code: the segment is rebuilt with tools/lib/build_seg.py and every src/<seg>/func_*.c whose bytes in the rebuilt segment
   differ from the ROM is moved too. Their callers and the rest of the segment fall back to the original assembly, so one pass is enough.
Use it after a batch of unchecked work (stopped agents, hand edits, the steps of tools/run/daily.sh); `make check` stays the judge."""
import shutil, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import match  # noqa: E402
import srcpath  # noqa: E402


def failing(seg: str) -> list:
    """The files of the segment that verify_src.py does not accept (it lists them in build/verify_failed_<seg>.txt)."""
    listed = ROOT / "build" / f"verify_failed_{seg}.txt"
    listed.unlink(missing_ok=True)
    subprocess.run([sys.executable, str(ROOT / "tools/check/verify_src.py"), seg], capture_output=True, text=True)
    return [ROOT / l for l in listed.read_text().split()] if listed.exists() else []


def park(f: Path, seg: str) -> None:
    wip = f.parent / "wip" if seg == "overlays" else ROOT / "src" / seg / "wip"
    wip.mkdir(exist_ok=True)
    shutil.move(str(f), str(wip / f.name))


def main():
    seg = sys.argv[1]
    limit = int(sys.argv[sys.argv.index("--max") + 1]) if "--max" in sys.argv else None
    bad = failing(seg)
    if limit is not None and len(bad) > limit:
        print(f"{seg}: {len(bad)} C functions fail (more than {limit}), none moved: {' '.join(f.stem for f in bad[:8])} ...")
        sys.exit(3)
    for f in bad:
        park(f, seg)
    print(f"{seg}: {len(bad)} C functions that do not compile or match moved to wip" + (": " + " ".join(f.stem for f in bad) if bad else ""))
    if seg == "overlays":
        return
    orig = {"boot": "build/boot.bin", "code": "extracted/0049_00C8A000.bin"}[seg]
    subprocess.run([sys.executable, str(ROOT / "tools/lib/build_seg.py"), seg, str(ROOT / orig)], capture_output=True, text=True)
    built = (ROOT / "build" / seg / f"{seg}.fn.bin").read_bytes()
    rom, base = match._rom(seg), match.SEG[seg][1]
    sizes = match._sizes(seg)
    moved = []
    for f in srcpath.files(seg):
        name = f.stem
        if name not in sizes:
            continue
        off = int(name.rsplit("_", 1)[1], 16) - base
        # the segment file starts at the first function: `built` and `rom` share the same origin
        if built[off:off + sizes[name]] != rom[off:off + sizes[name]]:
            park(f, seg)
            moved.append(name)
    print(f"{seg}: {len(moved)} C functions moved to wip" + (": " + " ".join(moved) if moved else ""))


if __name__ == "__main__":
    main()
