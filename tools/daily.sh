#!/bin/bash
# Unattended daily run, no agent needed. In WSL:  tools/daily.sh [hours=3]
#   1. permuter over every boot and code draft, closest to a match first (what tools/auto_loop.sh does)
#   2. overlays: the m2c draft of every function is tried (tools/overlay_auto.py), then the mechanical recipes, then promoted
#   3. what matched is tidied into src/, then names, srcsort and the full check (tools/wave_finish.sh)
#   4. only if the check passed: commit and push (set -e stops everything before that otherwise)
# Environment: NO_PUSH=1 commits without pushing, NO_COMMIT=1 leaves the result in the working tree.
# Runs at the lowest priority and refuses to start twice. Log: build/daily.log
set -e
cd "$(dirname "$0")/.."
exec 9>build/daily.lock
flock -n 9 || { echo "daily.sh already running"; exit 0; }
. ~/mm-venv/bin/activate
export PYTHONUNBUFFERED=1
renice -n 19 $$ > /dev/null 2>&1 || true
hours="${1:-3}"

git pull -q --ff-only || true
python3 tools/names.py code --apply-src > /dev/null
python3 tools/quarantine.py code
python3 tools/quarantine.py boot
python3 tools/build_seg.py code extracted/0049_00C8A000.bin > /dev/null
python3 tools/build_seg.py boot build/boot.bin > /dev/null

nice -n 19 python3 tools/permute_list.py --auto --hours "$hours"
python3 tools/tidy_perm.py code
python3 tools/tidy_perm.py boot

nice -n 19 python3 tools/overlay_auto.py run 0x400 4
nice -n 19 python3 tools/overlay_auto.py recipes 0x200 4
python3 tools/overlay_auto.py promote

bash tools/wave_finish.sh   # fails here, so nothing below runs, if a segment differs from the ROM or a style rule breaks

[ -n "${NO_COMMIT:-}" ] && exit 0
git add README.md docs/PROGRESS.md src/boot src/code src/overlays
if git diff --cached --quiet; then echo "nothing new today"; exit 0; fi
git commit -q -m "daily run: more verified functions

Found by the permuter and the automatic passes. make check: boot, code and overlays identical to the ROM, style rules OK."
git log -1 --format='committed %h %s'
[ -n "${NO_PUSH:-}" ] || git push -q
