#!/usr/bin/env python3
"""File every src/code/func_*.c into the folder of its source file (config/code.layout.txt). Idempotent. usage: srcsort.py"""
import shutil
import srcpath

for seg in sorted(srcpath.BUCKETED):
    n = 0
    for f in srcpath.files(seg):
        dst = srcpath.ROOT / "src" / seg / srcpath.bucket(seg, f.stem) / f.name
        if f != dst:
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.move(str(f), str(dst))
            n += 1
    print(f"{seg}: {n} files moved into their source-file folder")
