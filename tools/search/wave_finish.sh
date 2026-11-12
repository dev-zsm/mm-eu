#!/bin/bash
# After a wave of agents: apply the registered names, refresh the counters and run the full check.
# usage (in WSL): tools/search/wave_finish.sh
# Fails (non-zero) if a segment is not byte-identical to the ROM or a style rule is broken: do not commit then.
set -e
cd "$(dirname "$0")/../.."
. ~/mm-venv/bin/activate
python3 tools/layout/srcsort.py
python3 tools/lib/names.py code --apply-src
# QUARANTINE=1 (the daily round): a function that does not compile or match after the renaming goes back to wip/ instead of failing the check
[ -z "${QUARANTINE:-}" ] || for s in code boot overlays; do python3 tools/check/quarantine.py $s; done
bash tools/check/fastcheck.sh   # boot, code and overlays against the ROM, then the style rules, on the native WSL disk
python3 tools/check/progress.py boot code | grep -E '^\| `(boot|code)`'
