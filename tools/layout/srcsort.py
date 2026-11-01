#!/usr/bin/env python3
"""File every src/code/func_*.c into the folder of its source file (config/code/layout.txt). Idempotent. usage: srcsort.py"""
import shutil
import sys
from pathlib import Path

sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import srcpath  # noqa: E402

for seg in sorted(srcpath.BUCKETED):
    n = 0
    for f in srcpath.files(seg):
        dst = srcpath.ROOT / "src" / seg / srcpath.bucket(seg, f.stem) / f.name
        if f != dst:
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.move(str(f), str(dst))
            n += 1
    print(f"{seg}: {n} files moved into their source-file folder")
