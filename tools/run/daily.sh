#!/bin/bash
# Unattended daily run, no agent needed. In WSL:  tools/run/daily.sh [hours=3]
#   1. permuter over every boot, code and overlay draft (the overlay ones: wip files and m2c drafts of what the passes missed), closest to a match first
#   2. overlays: the m2c draft of every function is tried (tools/search/overlay_auto.py), then the mechanical recipes, then promoted
#   2b. the functions of the reference that compile to the bytes of the ROM (tools/search/ref_import.py), code and overlays
#   3. what matched is tidied into src/, then names, srcsort and the full check (tools/search/wave_finish.sh)
#   4. only if the check passed: commit and push (set -e stops everything before that otherwise)
# After every step above the work is checked against the ROM with the headers as they are now (checkpoint): a function that no longer
# compiles or matches goes back to wip/, a step that breaks more than a few is dropped whole, and what holds is committed at once, so a
# check that fails at the end costs the last step, not the three hours (the commits are squashed into one when the final check passes).
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
t0=$(date +%s)
python3 tools/check/selftest.py   # a broken tool stops the round before it spends hours

git fetch -q && { git rebase -q -X ours origin/main 2>/dev/null || git rebase --abort 2>/dev/null; } || true   # another machine may have pushed
python3 tools/lib/names.py code --apply-src > /dev/null
python3 tools/check/quarantine.py code
python3 tools/check/quarantine.py boot
python3 tools/search/ref_import.py heal > /dev/null   # links the code segment, and deletes the untracked files (left by a failed import) that keep it from linking
python3 tools/lib/build_seg.py boot build/boot.bin > /dev/null

base=$(git rev-parse HEAD)
git ls-files -o --exclude-standard src include config > build/daily.untracked   # files that are not the round's: never committed, never deleted
checkpoint() {
    if [ -n "${NO_COMMIT:-}" ]; then   # nothing is committed or reverted: the functions that fail only go back to wip
        for s in code boot overlays; do python3 tools/check/quarantine.py $s; done
    elif python3 tools/check/quarantine.py code --max 20 && python3 tools/check/quarantine.py boot --max 20 \
        && python3 tools/check/quarantine.py overlays --max 40; then
        git add -A -- src include config
        xargs -r -d '\n' git reset -q -- < build/daily.untracked
        git diff --cached --quiet || git commit -q -m "daily: $1"
    else
        echo "step '$1' broke the check: dropped"
        git reset -q --hard HEAD
        git ls-files -o --exclude-standard src include config | grep -vxFf build/daily.untracked | tr '\n' '\0' | xargs -0 -r rm -f
    fi
}

nice -n 19 python3 tools/search/permute_list.py --auto --hours "$(awk -v h="$hours" 'BEGIN { print h * 0.6 }')"   # 60%: it takes all it is given, and the closer below lives on what is left
python3 tools/search/tidy_perm.py code
python3 tools/search/tidy_perm.py boot
for d in build/perm_wins/ovl*/; do if [ -d "$d" ]; then python3 tools/search/tidy_perm.py "$(basename "$d")"; fi; done   # the overlays win too: one folder each
checkpoint permuter

nice -n 19 python3 tools/search/overlay_auto.py run 0x400 "${MM_JOBS:-$(nproc)}"
nice -n 19 python3 tools/search/overlay_auto.py recipes 0x200 "${MM_JOBS:-$(nproc)}"
python3 tools/search/overlay_auto.py promote
checkpoint "overlay passes"
python3 tools/signatures/retype.py config/overlays/signatures.txt   # type the actor handlers that just matched (kept only if they still match)
for seg in boot code overlays; do python3 tools/signatures/sig_header.py $seg --apply; done   # prototypes of the new functions into the headers, sources switched to them (kept only if they still match)
checkpoint "signatures"   # a header that breaks the files that include it is dropped here, with its step

# what the reference compiles to the bytes of the functions the passes above have just found: a new name or a new match makes more of its
# functions pairable. Each function is checked before it is kept; a failure here only skips this step. The first round clones it (NO_REF=1: skip).
if [ -z "${NO_REF:-}" ]; then
    { [ -d build/ref/mm ] || python3 tools/search/ref_import.py vendor; } && python3 tools/search/ref_import.py run && python3 tools/search/ref_import.py run overlays \
        || echo "reference import skipped"
    checkpoint "reference import"
fi

# what is left of the time budget goes to the adaptive closer (tools/search/close.py) over the near misses, closest first: code, boot, then the
# overlays, each with an equal share of what remains. The match server is used when it starts on this machine, else the compiles run in
# the process. A win is filed in src/ only after match.py and the style rules agree; wave_finish below checks everything again. NO_CLOSE=1: skip.
if [ -z "${NO_CLOSE:-}" ]; then
    python3 tools/fast/client.py stats > /dev/null 2>&1 || export MM_CLOSE_INPROC=1
    export MM_JOBS="${MM_JOBS:-$(nproc)}"
    specs=(code boot 0000-9999)
    for i in 0 1 2; do
        left=$(awk -v h="$hours" -v t0="$t0" -v now="$(date +%s)" -v n=$((3 - i)) 'BEGIN { l = (h * 3600 - (now - t0)) / n; print (l > 0 ? int(l) : 0) }')
        [ "$left" -ge 60 ] || break
        timeout "$left" nice -n 19 python3 tools/search/close.py sweep "${specs[$i]}" --time 60 || echo "closer on ${specs[$i]}: stopped"
    done
    python3 tools/search/close.py learn > /dev/null || true   # the wins of this round join config/search/close_stats.json
    checkpoint closer
fi

bash tools/search/wave_finish.sh   # fails here, so nothing below runs, if a segment differs from the ROM or a style rule breaks
# (the checkpoints stay committed then: tools/run/forever.sh resets to HEAD, and tools/run/push.sh checks and pushes them)
git reset -q --soft "$base"   # the check passed: one commit for the round, below

[ -n "${NO_COMMIT:-}" ] && exit 0
git add README.md docs/PROGRESS.md config/search/close_stats.json include src/boot src/code src/overlays
# the counters of docs/PROGRESS.md and README.md change with every check, and the statistics of the closer with every try: a round that found
# no function is not worth a commit (the statistics go with the next one that has)
if ! git diff --cached --name-only | grep -qv '^\(README.md\|docs/PROGRESS.md\|config/search/close_stats.json\)$'; then
    git reset -q README.md docs/PROGRESS.md config/search/close_stats.json; git checkout -q -- README.md docs/PROGRESS.md config/search/close_stats.json
    echo "nothing new today"; exit 0
fi
git commit -q -m "daily run: more verified functions

Found by the permuter and the automatic passes. make check: boot, code and overlays identical to the ROM, style rules OK."
git log -1 --format='committed %h %s'
bash tools/run/push.sh
