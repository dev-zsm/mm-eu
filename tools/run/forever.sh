#!/bin/bash
# Runs tools/run/daily.sh again and again, for a machine that stays on (see docs/TOOLS.md). tools/run/forever.sh [hours per round=3]
# A failed round (a check that does not pass) is thrown away so the next one starts from the last commit: the tracked files are
# reset and the files the round itself added to src/ and include/ are deleted (the untracked files present when it started stay).
# Every round leaves a line in build/rounds.log (tools/run/status.sh shows them, with an ALERT when nothing went well for 24 hours).
# A round that fails five times in a row the same way (same exit code, same commit, same last lines) is not repeated at once: the
# loop sleeps an hour between such failures, so a poisoned state costs 24 rounds a day instead of hundreds. A disk with under
# MM_MIN_FREE_GB (default 15) GB free makes it wait an hour too (tools/check/preflight.sh).
# shortcut: nothing stops it but the service or a kill, and a push that fails is only retried by the next round.
cd "$(dirname "$0")/../.."
hours="${1:-3}"
mkdir -p build
same=0; last_sig=""
while true; do
    if ! msg=$(bash tools/check/preflight.sh 2>&1); then
        echo "$(date -Is) rc=- $msg" | tr '\n' ' ' >> build/rounds.log; echo >> build/rounds.log
        sleep 3600; continue
    fi
    start=$(date +%s)
    git ls-files -o --exclude-standard src include | sort > build/untracked.before
    bash tools/run/daily.sh "$hours" 2>&1 | tee build/round.out
    rc=${PIPESTATUS[0]}
    if [ $rc -ne 0 ]; then
        echo "round failed ($rc), restoring the last commit"
        git reset -q --hard HEAD
        # reset leaves the new files: an imported file without the header or the symbols of the reset would break every later link
        git ls-files -o --exclude-standard src include | sort | comm -13 build/untracked.before - | tr '\n' '\0' | xargs -0 -r rm -f
    fi
    bash tools/run/push.sh > /dev/null 2>&1 || true   # sends what an earlier round committed while the push was not possible
    pushed=$(git rev-list --count origin/main..HEAD 2>/dev/null || echo "?")
    echo "$(date -Is) rc=$rc seconds=$(( $(date +%s) - start )) head=$(git rev-parse --short HEAD) unpushed=$pushed $(grep -m1 '^| `code`' docs/PROGRESS.md | tr -s ' ' | cut -c1-60)" >> build/rounds.log
    if [ $rc -eq 0 ]; then
        same=0
    else
        sig="$rc $(git rev-parse HEAD) $(tail -n 3 build/round.out | tr -d '0-9' | md5sum | cut -c1-12)"   # digits out: times and counters differ every round
        [ "$sig" = "$last_sig" ] && same=$((same + 1)) || same=1
        last_sig=$sig
        if [ $same -ge 5 ]; then
            echo "$(date -Is) ALERT: $same identical failures in a row (rc=$rc), sleeping an hour between rounds" >> build/rounds.log
            sleep 3600
        fi
    fi
    [ $(( $(date +%s) - start )) -lt 300 ] && sleep 600   # daily.sh refused to start or had nothing to do: do not spin
done
