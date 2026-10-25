#!/bin/bash
# Unattended loop, to run in WSL while no agent edits the wip drafts:  tools/auto_loop.sh [hours=1]
#   1. the permuter works through every wip draft, closest to a match first (tools/permute_list.py --auto)
#   2. what it matched is rewritten in the project style and moved to src/ (tools/tidy_perm.py)
#   3. names, full verification of boot and code, style rules (tools/wave_finish.sh)
# Nothing is committed unless AUTO_COMMIT=1 is set, and then only after the full check passed; nothing is ever pushed.
set -e
cd "$(dirname "$0")/.."
. ~/mm-venv/bin/activate
before=$(git ls-files 'src/code/func_*.c' 'src/boot/func_*.c' | wc -l)
python3 tools/names.py code --apply-src > /dev/null  # the link only knows the registered names of the functions in code
python3 tools/quarantine.py code  # unchecked work (stopped agents) must not break the segment: wrong functions go back to wip
python3 tools/quarantine.py boot
python3 tools/build_seg.py code extracted/0049_00C8A000.bin > /dev/null  # the permuter needs the objects of both segments
python3 tools/build_seg.py boot build/boot.bin > /dev/null
python3 tools/permute_list.py --auto --hours "${1:-1}"
python3 tools/tidy_perm.py code
python3 tools/tidy_perm.py boot
bash tools/wave_finish.sh
tail -5 build/perm/log_list.txt
if [ -n "${AUTO_COMMIT:-}" ]; then  # only reached when the full check passed (set -e); never pushes
  after=$(ls src/code/func_*.c src/boot/func_*.c | wc -l)
  git add README.md docs/PROGRESS.md src/boot src/code
  git commit -q -m "code, boot: $((after - before)) more verified C functions

Found by the permuter and by the agents. make check: boot and code MATCH, both segments identical
to the ROM, style rules OK."
  git log -1 --format='committed %h %s'
fi
