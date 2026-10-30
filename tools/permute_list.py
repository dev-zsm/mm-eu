#!/usr/bin/env python3
"""Run decomp-permuter on unmatched functions and keep what matches. Run in WSL.
usage: permute_list.py <list.txt> [seconds_per_function=100]      (one `<seg> <fn>` per line)
       permute_list.py --auto [--hours H] [--retry]                the queue is built from every wip draft
--auto measures every draft in src/<seg>/wip/ (hand-written assembly is skipped), sorts them by how close they are
(fewest differing instructions first, then smallest size difference) and gives more time to the closest ones:
300 s up to 5 differences, 120 s up to 10, 60 s otherwise. It stops at the deadline, skips what the log already holds
unless --retry, and can be stopped and restarted at any time.
A result is kept only if tools/match.py says MATCH; it is written to build/perm_wins/<fn>.c, raw. Make it readable
with `tools/tidy_perm.py <seg>`. Needs the objects of tools/build_seg.py (run `make verify` once).
Log: build/perm/log_list.txt"""
import os, re, signal, subprocess, sys, time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PERMUTER = ROOT / "tools/vendor/decomp-permuter/permuter.py"
sys.path.insert(0, str(ROOT / "tools"))
import names  # noqa: E402
import objcache  # noqa: E402
import wave  # noqa: E402

LOG = ROOT / "build/perm/log_list.txt"
WINS = ROOT / "build/perm_wins"


def measure(seg: str, fn: str):
    """Sort key of a draft: (0, differing instructions), (1, size difference), or None when it cannot be measured."""
    r = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), seg, fn, str(ROOT / "src" / seg / "wip" / f"{fn}.c")],
                       capture_output=True, text=True)
    m = re.search(r"(\d+)/(\d+) instructions differ", r.stdout)
    if m:
        return 0, int(m.group(1))
    m = re.search(r"SIZE DIFFERS \(rom (0x[0-9a-f]+), ours (0x[0-9a-f]+)\)", r.stdout)
    if m:
        return 1, abs(int(m.group(1), 16) - int(m.group(2), 16))
    return None


def auto_queue(tried: set):
    queue = []
    for seg in ("code", "boot"):
        skip = {n for n, _, _, hand in wave.functions(seg) if hand}
        asm_only = ROOT / "config" / f"{seg}.asm_only.txt"
        skip |= set(asm_only.read_text().split()) if asm_only.exists() else set()
        for f in sorted((ROOT / "src" / seg / "wip").glob("func_*.c")):
            if f.stem in skip or f.stem in tried:
                continue
            key = measure(seg, f.stem)
            if key is None:
                continue
            budget = (300 if key[1] <= 5 else 120 if key[1] <= 10 else 60) if key[0] == 0 else 60
            queue.append((key, seg, f.stem, budget))
    return [(seg, fn, budget) for _, seg, fn, budget in sorted(queue)]


def run_one(seg: str, fn: str, budget: int) -> str:
    wip = ROOT / "src" / seg / "wip" / f"{fn}.c"
    text = wip.read_text()
    if "\r" in text:
        wip.write_text(text.replace("\r", ""))  # the permuter and its compile script choke on CRLF
    setup = subprocess.run([sys.executable, str(ROOT / "tools/permute_setup.py"), seg, fn], capture_output=True, text=True)
    if setup.returncode:
        return "setup failed"
    d = ROOT / "build/perm" / fn
    # own process group: on timeout the worker processes must die too, or they pile up and eat memory
    p = subprocess.Popen([sys.executable, str(PERMUTER), str(d), "-j", str(os.cpu_count() or 4), "--stop-on-zero"],
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
    WINS.mkdir(parents=True, exist_ok=True)
    out = WINS / f"{fn}.c"
    out.write_text(objcache.directives(text) + names.apply(best[0].read_text(), names.load(seg)))
    r = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), seg, fn, str(out)], capture_output=True, text=True)
    if "MATCH" in r.stdout and "differ" not in r.stdout:
        return f"MATCH -> {out.relative_to(ROOT)}"
    out.unlink()
    return "the permuter claimed a match but tools/match.py disagrees"


def main():
    LOG.parent.mkdir(parents=True, exist_ok=True)
    auto = "--auto" in sys.argv
    tried = set() if "--retry" in sys.argv else \
        {l.split()[1] for l in LOG.read_text().splitlines() if l[:1].isdigit()} if LOG.exists() else set()
    if auto:
        hours = float(sys.argv[sys.argv.index("--hours") + 1]) if "--hours" in sys.argv else 1.0
        todo = auto_queue(tried)
        deadline = time.time() + hours * 3600
    else:
        budget = int(sys.argv[2]) if len(sys.argv) > 2 else 100
        todo = [(a, b, budget) for a, b in (l.split() for l in Path(sys.argv[1]).read_text().splitlines() if l.strip())
                if b not in tried]
        deadline = float("inf")
    won = done = 0
    for n, (seg, fn, budget) in enumerate(todo, 1):
        if time.time() > deadline:
            break
        t0 = time.time()
        status = run_one(seg, fn, budget) if (ROOT / "src" / seg / "wip" / f"{fn}.c").exists() else "no wip draft"
        won += status.startswith("MATCH")
        done += 1
        with LOG.open("a") as f:
            f.write(f"{n}/{len(todo)} {fn} {time.time() - t0:.0f}s {status}\n")
    with LOG.open("a") as f:
        f.write(f"DONE: {won} matched out of {done} tried ({len(todo)} queued)\n")


if __name__ == "__main__":
    main()
