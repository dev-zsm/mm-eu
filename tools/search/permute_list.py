#!/usr/bin/env python3
"""Run decomp-permuter on unmatched functions and keep what matches. Run in WSL.
usage: permute_list.py <list.txt> [seconds_per_function=100]      (one `<seg> <fn>` per line)
       permute_list.py --auto [--hours H] [--retry]                the queue is built from every wip draft
--auto measures every draft in src/<seg>/wip/ (hand-written assembly is skipped), sorts them by how close they are
(fewest differing instructions first, then smallest size difference) and gives more time to the closest ones:
300 s up to 5 differences, 120 s up to 10, 60 s otherwise. It stops at the deadline, skips what the log already holds
unless --retry, and can be stopped and restarted at any time.
A result is kept only if tools/lib/match.py says MATCH; it is written to build/perm_wins/<fn>.c, raw. Make it readable
with `tools/search/tidy_perm.py <seg>`. Needs the objects of tools/lib/build_seg.py (run `make verify` once).
Log: build/perm/log_list.txt"""
import os, re, signal, subprocess, sys, tempfile, time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
PERMUTER = ROOT / "tools/vendor/decomp-permuter/permuter.py"
sys.path[:0] = [str(d) for d in Path(__file__).resolve().parents[1].glob("*/") if d.name != "vendor"]
import names  # noqa: E402
import srcpath  # noqa: E402
import objcache  # noqa: E402
import wave  # noqa: E402
import match  # noqa: E402
import auto_match  # noqa: E402
import permute_setup  # noqa: E402
import json  # noqa: E402

LOG = ROOT / "build/perm/log_list.txt"
WINS = ROOT / "build/perm_wins"
MEASURED = ROOT / "build/perm/measured.json"   # {"ovl0051/func_80000000": [kind, n]}: a draft is measured once
OVERLAY_MAX = 0x180      # the permuter only has a chance on small functions
OVERLAY_MEASURE_MINUTES = 40   # per run: the rest is measured by the next runs, from the cache


def tag(seg: str, fn: str) -> str:
    return f"{seg}/{fn}" if seg.startswith("ovl") else fn


def measure(seg: str, fn: str):
    """Sort key of a draft: (0, differing instructions), (1, size difference), or None when it cannot be measured."""
    r = subprocess.run([sys.executable, str(ROOT / "tools/lib/match.py"), seg, fn, str(permute_setup.draft(seg, fn))],
                       capture_output=True, text=True)
    m = re.search(r"(\d+)/(\d+) instructions differ", r.stdout)
    if m:
        return 0, int(m.group(1))
    m = re.search(r"SIZE DIFFERS \(rom (0x[0-9a-f]+), ours (0x[0-9a-f]+)\)", r.stdout)
    if m:
        return 1, abs(int(m.group(1), 16) - int(m.group(2), 16))
    return None


def auto_queue(tried: set, deadline: float = float('inf')):
    queue = []
    for seg in ("code", "boot"):
        skip = {n for n, _, _, hand in wave.functions(seg) if hand}
        asm_only = ROOT / "config" / seg / "asm_only.txt"
        skip |= set(asm_only.read_text().split()) if asm_only.exists() else set()
        for f in sorted((ROOT / "src" / seg / "wip").glob("func_*.c")):
            if f.stem in skip or f.stem in tried:
                continue
            if time.time() > deadline:   # the budget of the run: what is not measured yet is, by the next run
                continue
            key = measure(seg, f.stem)
            if key is None:
                continue
            budget = (300 if key[1] <= 5 else 120 if key[1] <= 10 else 60) if key[0] == 0 else 60
            queue.append((key, seg, f.stem, budget))
    queue += overlay_queue(tried)
    return [(seg, fn, budget) for _, seg, fn, budget in sorted(queue)]


def overlay_drafts(seg: str):
    """Overlay functions with a draft to measure: the wip files, then the m2c drafts of what the automatic passes missed
    (m2c is run here, on demand, and the draft kept in build/auto_drafts/<seg>/)."""
    base = srcpath.overlay_dir(seg[3:])
    for p in sorted((base / "wip").glob("func_*.c")):
        yield p.stem, None
    log = ROOT / "build/auto_match" / f"{seg}.txt"
    if not log.exists():
        return
    sizes = match._sizes(seg)
    missed = [l.split()[0] for l in log.read_text().splitlines() if l.endswith("no match")]
    text = None
    for fn in missed:
        if sizes.get(fn, 1 << 30) > OVERLAY_MAX or auto_match.have_c(seg, fn):
            continue
        d = ROOT / "build/auto_drafts" / seg / f"{fn}.c"
        if not d.exists():
            text = text or match.asm_file(seg).read_text()
            chunk = next(c for c in re.split(r"(?=^nonmatching )", text, flags=re.M)[1:] if c.startswith(f"nonmatching {fn},"))
            yield fn, text[:text.index("nonmatching ")] + chunk
        else:
            yield fn, None


def overlay_queue(tried: set):
    cache = json.loads(MEASURED.read_text()) if MEASURED.exists() else {}
    deadline = time.time() + OVERLAY_MEASURE_MINUTES * 60
    queue = []
    for i in auto_match_overlays():
        seg = f"ovl{i}"
        for fn, asm in overlay_drafts(seg):
            t = tag(seg, fn)
            if t in tried:
                continue
            if t not in cache:
                if time.time() > deadline:
                    continue
                if asm is not None and not make_draft(seg, fn, asm):
                    cache[t] = None
                    continue
                cache[t] = measure(seg, fn)
            key = cache[t]
            if key is None or (key[0] == 0 and key[1] > 30):
                continue
            budget = (300 if key[1] <= 5 else 120 if key[1] <= 10 else 60) if key[0] == 0 else 30
            queue.append((tuple(key), seg, fn, budget))
    MEASURED.parent.mkdir(parents=True, exist_ok=True)
    MEASURED.write_text(json.dumps(cache))
    return queue


def auto_match_overlays():
    return [l.split()[0] for l in (ROOT / "config" / "overlays" / "list.txt").read_text().splitlines() if l.strip()]


def make_draft(seg: str, fn: str, asm: str) -> bool:
    """m2c draft of one overlay function, written to build/auto_drafts/<seg>/<fn>.c."""
    with tempfile.TemporaryDirectory() as d:
        s = Path(d) / f"{fn}.s"
        s.write_text(asm)
        r = subprocess.run([sys.executable, str(auto_match.M2C), "-t", "mips-ido-c", "--valid-syntax", str(s)],
                           capture_output=True, text=True)
    if r.returncode or "M2C_ERROR" in r.stdout or not re.search(rf"[ *]{fn}\(", r.stdout):
        return False
    out = ROOT / "build/auto_drafts" / seg / f"{fn}.c"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text('#include "types.h"\n#include "m2c_macros.h"\n\n' + r.stdout.replace("void *", "u8 *"))
    return True


def run_one(seg: str, fn: str, budget: int) -> str:
    wip = permute_setup.draft(seg, fn)
    text = wip.read_text()
    if "\r" in text:
        wip.write_text(text.replace("\r", ""))  # the permuter and its compile script choke on CRLF
    setup = subprocess.run([sys.executable, str(ROOT / "tools/search/permute_setup.py"), seg, fn], capture_output=True, text=True)
    if setup.returncode:
        return "setup failed"
    d = permute_setup.workdir(seg, fn)
    # own process group: on timeout the worker processes must die too, or they pile up and eat memory
    p = subprocess.Popen([sys.executable, str(PERMUTER), str(d), "-j", str(objcache.JOBS), "--stop-on-zero"],
                         stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, start_new_session=True,
                         preexec_fn=lambda: os.nice(19))  # lowest priority: the checks and the agents keep the CPU
    try:
        p.wait(timeout=budget)
    except subprocess.TimeoutExpired:
        os.killpg(p.pid, signal.SIGKILL)
        p.wait()
    best = sorted(d.glob("output-0-*/source.c"))
    if not best:
        return "no match"
    wins = WINS / seg if seg.startswith("ovl") else WINS
    wins.mkdir(parents=True, exist_ok=True)
    out = wins / f"{fn}.c"
    out.write_text(objcache.directives(text) + names.apply(best[0].read_text(), names.load(seg)))
    r = subprocess.run([sys.executable, str(ROOT / "tools/lib/match.py"), seg, fn, str(out)], capture_output=True, text=True)
    if "MATCH" in r.stdout and "differ" not in r.stdout:
        return f"MATCH -> {out.relative_to(ROOT)}"
    out.unlink()
    return "the permuter claimed a match but tools/lib/match.py disagrees"


def main():
    LOG.parent.mkdir(parents=True, exist_ok=True)
    auto = "--auto" in sys.argv
    tried = set() if "--retry" in sys.argv else \
        {l.split()[1] for l in LOG.read_text().splitlines() if l[:1].isdigit()} if LOG.exists() else set()
    if auto:
        hours = float(sys.argv[sys.argv.index("--hours") + 1]) if "--hours" in sys.argv else 1.0
        global OVERLAY_MEASURE_MINUTES
        OVERLAY_MEASURE_MINUTES = min(OVERLAY_MEASURE_MINUTES, hours * 15)   # measuring never takes more than a quarter of the run
        deadline = time.time() + hours * 3600   # before the queue: building it compiles every draft and takes long on a cold cache
        todo = auto_queue(tried, deadline)
    else:
        budget = int(sys.argv[2]) if len(sys.argv) > 2 else 100
        todo = [(a, b, budget) for a, b in (l.split() for l in Path(sys.argv[1]).read_text().splitlines() if l.strip())
                if tag(a, b) not in tried]
        deadline = float("inf")
    won = done = 0
    for n, (seg, fn, budget) in enumerate(todo, 1):
        if time.time() > deadline:
            break
        t0 = time.time()
        status = run_one(seg, fn, budget) if permute_setup.draft(seg, fn) else "no wip draft"
        won += status.startswith("MATCH")
        done += 1
        with LOG.open("a") as f:
            f.write(f"{n}/{len(todo)} {tag(seg, fn)} {time.time() - t0:.0f}s {status}\n")
    with LOG.open("a") as f:
        f.write(f"DONE: {won} matched out of {done} tried ({len(todo)} queued)\n")


if __name__ == "__main__":
    main()
