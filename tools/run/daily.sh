#!/bin/bash
# Unattended daily run, no agent needed. In WSL:  tools/run/daily.sh [hours=3]
#   1. permuter over every boot, code and overlay draft (the overlay ones: wip files and m2c drafts of what the passes missed), closest to a match first
#   2. overlays: the m2c draft of every function is tried (tools/search/overlay_auto.py), then the mechanical recipes, then promoted
#   2b. the functions of the reference that compile to the bytes of the ROM (tools/search/ref_import.py), code and overlays
#   3. what matched is tidied into src/, then names, srcsort and the full check (tools/search/wave_finish.sh)
#   4. only if the check passed: commit and push (set -e stops everything before that otherwise)
# Environment: NO_PUSH=1 commits without pushing, NO_COMMIT=1 leaves the result in the working tree.
# Runs at the lowest priority and refuses to start twice. Log: build/daily.log
set -e
cd "$(dirname "$0")/../.."
exec 9>build/daily.lock
flock -n 9 || { echo "daily.sh already running"; exit 0; }
. ~/mm-venv/bin/activate
export PYTHONUNBUFFERED=1
renice -n 19 $$ > /dev/null 2>&1 || true
hours="${1:-3}"
python3 tools/check/selftest.py   # a broken tool stops the round before it spends hours

git fetch -q && { git rebase -q -X ours origin/main 2>/dev/null || git rebase --abort 2>/dev/null; } || true   # another machine may have pushed
python3 tools/lib/names.py code --apply-src > /dev/null
python3 tools/check/quarantine.py code
python3 tools/check/quarantine.py boot
python3 tools/lib/build_seg.py code extracted/0049_00C8A000.bin > /dev/null
python3 tools/lib/build_seg.py boot build/boot.bin > /dev/null

nice -n 19 python3 tools/search/permute_list.py --auto --hours "$hours"
python3 tools/search/tidy_perm.py code
python3 tools/search/tidy_perm.py boot
for d in build/perm_wins/ovl*/; do if [ -d "$d" ]; then python3 tools/search/tidy_perm.py "$(basename "$d")"; fi; done   # the overlays win too: one folder each

nice -n 19 python3 tools/search/overlay_auto.py run 0x400 "${MM_JOBS:-$(nproc)}"
nice -n 19 python3 tools/search/overlay_auto.py recipes 0x200 "${MM_JOBS:-$(nproc)}"
python3 tools/search/overlay_auto.py promote
python3 tools/signatures/retype.py config/overlays/signatures.txt   # type the actor handlers that just matched (kept only if they still match)
for seg in boot code overlays; do python3 tools/signatures/sig_header.py $seg --apply; done   # prototypes of the new functions into the headers, sources switched to them (kept only if they still match)

# what the reference compiles to the bytes of the functions the passes above have just found: a new name or a new match makes more of its
# functions pairable. Each function is checked before it is kept; a failure here only skips this step. The first round clones it (NO_REF=1: skip).
if [ -z "${NO_REF:-}" ]; then
    { [ -d build/ref/mm ] || python3 tools/search/ref_import.py vendor; } && python3 tools/search/ref_import.py run && python3 tools/search/ref_import.py run overlays \
        || echo "reference import skipped"
fi

bash tools/search/wave_finish.sh   # fails here, so nothing below runs, if a segment differs from the ROM or a style rule breaks

[ -n "${NO_COMMIT:-}" ] && exit 0
git add README.md docs/PROGRESS.md include src/boot src/code src/overlays
# the counters of docs/PROGRESS.md and README.md change with every check: a round that found no function is not worth a commit
if ! git diff --cached --name-only | grep -qv '^\(README.md\|docs/PROGRESS.md\)$'; then
    git reset -q README.md docs/PROGRESS.md; git checkout -q -- README.md docs/PROGRESS.md
    echo "nothing new today"; exit 0
fi
git commit -q -m "daily run: more verified functions

Found by the permuter and the automatic passes. make check: boot, code and overlays identical to the ROM, style rules OK."
git log -1 --format='committed %h %s'
bash tools/run/push.sh
