#!/bin/bash
# After a wave of agents: apply the registered names, refresh the counters and run the full check.
# usage (in WSL): tools/wave_finish.sh
# Fails (non-zero) if a segment is not byte-identical to the ROM or a style rule is broken: do not commit then.
set -e
cd "$(dirname "$0")/.."
. ~/mm-venv/bin/activate
python3 tools/srcsort.py
python3 tools/names.py code --apply-src
bash tools/verify_all.sh boot
bash tools/verify_all.sh code
bash tools/check_style.sh
python3 tools/progress.py boot code | grep -E '^\| `(boot|code)`'
