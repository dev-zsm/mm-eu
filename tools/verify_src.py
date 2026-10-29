#!/usr/bin/env python3
"""Re-verify every src/<seg>/<fn>.c against the ROM. Run in WSL. usage: verify_src.py <seg>       (seg: boot, code, or overlays for every overlay of src/overlays/<file index>/)
Fast: files are checked on every core, compiled objects are cached by content (objcache), and a MATCH verdict is cached
by the SHA-256 of (source, flags, compiler, headers, the ROM bytes of the function, the name table, this checker), so
only functions that changed are compiled again. Delete build/cache/ to force a full check."""
import json, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import match, objcache, srcpath

seg = sys.argv[1]


def listing():
    if seg == "overlays":
        return sorted((match.ROOT / "src" / "overlays").glob("*/func_*.c"))
    return srcpath.files(seg)


def segment_of(f: Path) -> str:
    return "ovl" + f.parent.name if seg == "overlays" else seg


checker = Path(match.__file__).read_bytes()
verdicts = objcache.CACHE / f"verdict_{seg}.json"
known = set(json.loads(verdicts.read_text())) if verdicts.exists() else set()


def check(f: Path):
    name = f.stem
    key = None
    try:
        want, _ = match.original(segment_of(f), name)
        flags = match.file_flags(f)
        key = objcache.digest(b"verdict", checker, " ".join(flags).encode(), f.read_bytes().replace(b"\r\n", b"\n"),
                              objcache.headers().encode(), want, match.NAMES.get(name, name).encode(),
                              b"53" if objcache.uses_ido53(f) else b"71")
        if key in known:
            return name, key, True
        got, masks = match.compiled(f, name, flags, len(want))
        if len(got) > len(want) and not any(got[len(want):]):
            got = got[:len(want)]
        return name, key, len(want) == len(got) and match.mask(want, masks) == match.mask(got, masks)
    except Exception:  # compile error, symbol missing, ...
        return name, key, False


with ThreadPoolExecutor(objcache.JOBS) as ex:
    results = list(ex.map(check, listing()))
ok = [n for n, _, good in results if good]
bad = [n for n, _, good in results if not good]
objcache.CACHE.mkdir(parents=True, exist_ok=True)
verdicts.write_text(json.dumps(sorted({k for _, k, good in results if good and k})))  # only the current keys: no stale growth
print(f"{seg}: {len(ok)} MATCH, {len(bad)} not matching")
for n in bad:
    print("  FAIL", n)
