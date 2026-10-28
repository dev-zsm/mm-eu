#!/usr/bin/env python3
"""Mass production for the overlays, with no agent: try the m2c draft of every function (tools/auto_match.py) overlay after
overlay, then promote what matched to src/overlays/<index>/. Run in WSL (venv, MM_CC set).
usage: overlay_auto.py run [max_size_hex=0x200] [jobs=6]   try every overlay (resume-safe: the log of each overlay is kept)
       overlay_auto.py recipes [max_size_hex=0x100] [jobs=6]  second pass: mechanical tricks on the drafts that did not match
       overlay_auto.py promote                              move build/auto_match/ovlNNNN/<fn>.c to src/overlays/NNNN/ (checked again)
A promoted file is checked with tools/match.py first; a file that does not match is left in build/."""
import subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def overlays():
    return [l.split()[0] for l in (ROOT / "config" / "overlays.txt").read_text().splitlines() if l.strip()]


def run(max_size, jobs):
    for i in overlays():
        subprocess.run([sys.executable, str(ROOT / "tools/auto_match.py"), f"ovl{i}", max_size, str(jobs)], cwd=ROOT)


def recipes(max_size, jobs):
    """Second pass on what the plain drafts missed: the mechanical tricks of tools/auto_recipes.py."""
    for i in overlays():
        subprocess.run([sys.executable, str(ROOT / "tools/auto_recipes.py"), f"ovl{i}", max_size, str(jobs)], cwd=ROOT)


def project_form(f):
    """The draft written for the project's header (include/m2c_compat.h replaces the m2c one)."""
    return f.read_text().replace('#include "m2c_macros.h"', '#include "m2c_compat.h"')


def confirm(f):
    seg, fn = f.parent.name[:7], f.stem
    tmp = ROOT / "build" / f"promote_{seg}_{fn}.c"
    tmp.write_text(project_form(f))
    r = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), seg, fn, str(tmp)], capture_output=True, text=True)
    tmp.unlink()
    return f, "MATCH" in r.stdout and r.returncode == 0


def promote():
    from multiprocessing import Pool
    todo = [f for f in sorted((ROOT / "build" / "auto_match").glob("ovl[0-9][0-9][0-9][0-9]*/func_*.c"))
            if not (ROOT / "src" / "overlays" / f.parent.name[3:7] / f.name).exists()]
    n = 0
    with Pool(6) as pool:
        for f, ok in pool.imap_unordered(confirm, todo):
            if ok:
                dst = ROOT / "src" / "overlays" / f.parent.name[3:7] / f.name
                dst.parent.mkdir(parents=True, exist_ok=True)
                dst.write_text(project_form(f))
                n += 1
    print(f"{n} promoted, {len(todo) - n} not confirmed")


if __name__ == "__main__":
    if sys.argv[1:2] == ["run"]:
        run(sys.argv[2] if len(sys.argv) > 2 else "0x200", int(sys.argv[3]) if len(sys.argv) > 3 else 6)
    elif sys.argv[1:2] == ["recipes"]:
        recipes(sys.argv[2] if len(sys.argv) > 2 else "0x100", int(sys.argv[3]) if len(sys.argv) > 3 else 6)
    elif sys.argv[1:2] == ["promote"]:
        promote()
    else:
        sys.exit(__doc__)
