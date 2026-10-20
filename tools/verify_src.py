#!/usr/bin/env python3
"""Re-verify every src/<seg>/<fn>.c against the ROM. Run in WSL. usage: verify_src.py <seg>"""
import struct, sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import match

seg = sys.argv[1]
ok, bad = [], []
for f in sorted((match.ROOT / "src" / seg).glob("func_*.c")):
    name = f.stem
    try:
        want, _ = match.original(seg, name)
        got, masks = match.compiled(f, name, match.file_flags(f))
        if len(got) > len(want) and not any(got[len(want):]):
            got = got[:len(want)]
        good = len(want) == len(got) and match.mask(want, masks) == match.mask(got, masks)
    except Exception as e:  # compile error, symbol missing, ...
        good = False
    (ok if good else bad).append(name)
print(f"{seg}: {len(ok)} MATCH, {len(bad)} not matching")
for n in bad:
    print("  FAIL", n)
