#!/usr/bin/env python3
"""Source rules every file of src/boot, src/code and src/overlays must respect (see docs/CONTRIBUTING.md). wip/ is not checked.
Each file is read once. Exit status is 0 only if no rule is broken."""
import json, os, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
RULES = [  # (description, pattern, exception pattern)
    ("inline assembly", re.compile(r"__asm__|\basm *\(|\basm +volatile"), None),
    ("#pragma other than the sqrtf/fabsf idiom", re.compile(r"#pragma"), re.compile(r"pragma intrinsic \((sqrtf|fabsf)\)")),
    ("reference to another project or a web address", re.compile(r"https?://|zeldaret"), None),
]


def sources():
    for top in ("boot", "code", "overlays"):
        for d, dirs, files in os.walk(ROOT / "src" / top):
            dirs[:] = [x for x in dirs if x != "wip"]
            for f in files:
                if f.endswith(".c"):
                    yield Path(d) / f


CACHE = ROOT / "build" / "style_cache.json"  # clean files by (mtime, size): reading 6,000 small files on /mnt/c takes a minute


def main():
    hits = {r[0]: [] for r in RULES}
    n = ido53 = 0
    try:
        known = json.loads(CACHE.read_text())
    except (OSError, ValueError):
        known = {}
    clean = {}
    for p in sources():
        n += 1
        key, st = p.relative_to(ROOT).as_posix(), p.stat()
        sig = [st.st_mtime_ns, st.st_size]
        if key in known and known[key][:2] == sig:
            ido53 += known[key][2]
            clean[key] = known[key]
            continue
        found, own = False, 0
        for i, line in enumerate(p.read_text(errors="replace").splitlines(), 1):
            own += "COMPILER: ido53" in line
            for desc, pat, exc in RULES:
                if pat.search(line) and not (exc and exc.search(line)):
                    hits[desc].append(f"{key}:{i}:{line.strip()}")
                    found = True
        ido53 += own
        if not found:
            clean[key] = sig + [own]
    CACHE.write_text(json.dumps(clean))
    fail = False
    for desc, found in hits.items():
        if found:
            fail = True
            print(f"FAIL {desc}:")
            print("\n".join(found[:10]))
    print(f"note: {ido53} files are built with IDO 5.3 (each must fail with IDO 7.1, see CONTRIBUTING.md)")
    if not fail:
        print(f"style: OK ({n} files)")
    return int(fail)


if __name__ == "__main__":
    sys.exit(main())
