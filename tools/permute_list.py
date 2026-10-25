#!/usr/bin/env python3
"""Run decomp-permuter on a chosen list of unmatched functions, e.g. the near misses of a wave.
Run in WSL.  usage: permute_list.py <list.txt> [seconds_per_function=100]   (one `<seg> <fn>` per line)
Needs the objects of tools/build_seg.py (run `make verify` once). A result is kept only if tools/match.py says MATCH;
it is written to build/perm_wins/<fn>.c and still has to be made readable (the permuter output is raw): move it to
src/<seg>/ after cleaning it, check it with `tools/mm match`, and delete the wip draft. Log: build/perm/log_list.txt"""
import os, signal, subprocess, sys, time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PERMUTER = ROOT / "tools/vendor/decomp-permuter/permuter.py"
sys.path.insert(0, str(ROOT / "tools"))
import names  # noqa: E402


def main():
    budget = int(sys.argv[2]) if len(sys.argv) > 2 else 100
    log = ROOT / "build/perm/log_list.txt"
    log.parent.mkdir(parents=True, exist_ok=True)
    wins = ROOT / "build/perm_wins"
    wins.mkdir(parents=True, exist_ok=True)
    todo = [l.split() for l in Path(sys.argv[1]).read_text().splitlines() if l.strip()]
    won = 0
    for n, (seg, fn) in enumerate(todo, 1):
        wip = ROOT / "src" / seg / "wip" / f"{fn}.c"
        if not wip.exists():
            continue
        text = wip.read_text()
        if "\r" in text:
            wip.write_text(text.replace("\r", ""))  # the permuter and its compile script choke on CRLF
        t0 = time.time()
        setup = subprocess.run([sys.executable, str(ROOT / "tools/permute_setup.py"), seg, fn], capture_output=True, text=True)
        status = "setup failed"
        if setup.returncode == 0:
            d = ROOT / "build/perm" / fn
            # own process group: on timeout the worker processes must die too, or they pile up and eat memory
            p = subprocess.Popen([sys.executable, str(PERMUTER), str(d), "-j", str(os.cpu_count() or 4), "--stop-on-zero"],
                                 stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, start_new_session=True)
            try:
                p.wait(timeout=budget)
            except subprocess.TimeoutExpired:
                os.killpg(p.pid, signal.SIGKILL)
                p.wait()
            status = "no match"
            best = sorted(d.glob("output-0-*/source.c"))
            if best:
                flags = text.splitlines()[0] if text.startswith("// FLAGS") else ""
                out = wins / f"{fn}.c"
                out.write_text((flags + "\n" if flags else "") + names.apply(best[0].read_text(), names.load(seg)))
                r = subprocess.run([sys.executable, str(ROOT / "tools/match.py"), seg, fn, str(out)], capture_output=True, text=True)
                if "MATCH" in r.stdout and "differ" not in r.stdout:
                    won += 1
                    status = f"MATCH -> {out.relative_to(ROOT)}"
                else:
                    out.unlink()
                    status = "the permuter claimed a match but tools/match.py disagrees"
        with log.open("a") as f:
            f.write(f"{n}/{len(todo)} {fn} {time.time() - t0:.0f}s {status}\n")
    with log.open("a") as f:
        f.write(f"DONE: {won} matched out of {len(todo)}\n")


if __name__ == "__main__":
    main()
