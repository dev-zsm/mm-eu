#!/usr/bin/env python3
"""Re-verify every src/<seg>/<fn>.c against the ROM. Run in WSL. usage: verify_src.py <seg>       (seg: boot, code, or overlays for every overlay of src/overlays/<file index>/)
Fast: files are checked on every core, compiled objects are cached by content (objcache), and a MATCH verdict is cached
by the SHA-256 of (source, flags, compiler, the headers the file can reach, the ROM bytes of the function, its name, the
checking tools) together with the address of every symbol its code refers to, so only functions whose inputs changed are
checked again. MM_FULL=1 ignores the cached verdicts; an empty MM_CACHE also compiles everything again.
Exit status is 0 only if every function matches."""
import json, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import match, objcache, srcpath

seg = sys.argv[1]


def listing():
    if seg == "overlays":
        return sorted((match.ROOT / "src" / "overlays").glob("*/func_*.c"))
    return srcpath.files(seg)


def segment_of(f: Path) -> str:
    return "ovl" + srcpath.overlay_index(f.parent.name) if seg == "overlays" else seg


checker = b"".join(Path(p).read_bytes() for p in (__file__, match.__file__, srcpath.__file__, match._names.__file__))
verdicts = objcache.STATE / f"verdict_{seg}.json"
# the manifest of the last run: {key of a function that matched: {symbol its code refers to: the address it stood for}}
try:
    known = {} if objcache.FULL else json.loads(verdicts.read_text())
    known = known if isinstance(known, dict) else {}
except (OSError, ValueError):
    known = {}
targets = {}


def check(f: Path):
    name = f.stem
    key = None
    try:
        want, _ = match.original(segment_of(f), name)
        flags = match.file_flags(f)
        source = f.read_bytes().replace(b"\r\n", b"\n")
        ido = "53" if objcache.uses_ido53(f) else "71"
        key = objcache.digest(b"verdict", checker, objcache.flag_key(flags), source, objcache.deps(source, f, flags), want,
                              match.real_name(f, name).encode(), objcache.ident(ido))
        # a name table that moved a symbol this function refers to calls for a new comparison of its targets
        if key in known and all(match._address(s) == a for s, a in known[key].items()):
            targets[key] = known[key]
            return name, key, True
        for attempt in range(3):  # a compiler killed under load is retried; a real error fails the same way every time
            try:
                got, masks = match.compiled(f, name, flags, len(want))
                break
            except Exception:
                if attempt == 2:
                    raise
        if len(got) > len(want) and not any(got[len(want):]):
            got = got[:len(want)]
        same = len(want) == len(got) and match.mask(want, masks) == match.mask(got, masks)
        # the masked fields must also point where the ROM's do: a wrong callee or data symbol has the right bytes but the wrong address
        targets[key] = {s: match._address(s) for _, _, s in match.last_relocs()}
        return name, key, same and not match.check_targets(want, got, match.last_relocs())
    except Exception:  # compile error, symbol missing, ...
        return name, key, False


with ThreadPoolExecutor(objcache.JOBS) as ex:
    results = list(ex.map(check, listing()))
ok = [n for n, _, good in results if good]
bad = [n for n, _, good in results if not good]
objcache.used()
verdicts.write_text(json.dumps({k: targets[k] for _, k, good in results if good and k}))  # only the current keys: no stale growth
print(f"{seg}: {len(ok)} MATCH, {len(bad)} not matching")
if match.TARGET_STATS:   # only the functions compiled in this run: a verdict kept in the cache is not looked at again
    print(f"  call and data targets compared with the ROM in this run: {match.TARGET_STATS['compared']}, of unknown address (not compared): {match.TARGET_STATS['unknown address']}")
for n in bad:
    print("  FAIL", n)
# the files that fail, for tools/check/quarantine.py (which moves them to wip)
(match.ROOT / "build").mkdir(exist_ok=True)
(match.ROOT / "build" / f"verify_failed_{seg}.txt").write_text("".join(f"{f.relative_to(match.ROOT).as_posix()}\n" for f, (_, _, good) in zip(listing(), results) if not good))
sys.exit(1 if bad else 0)
