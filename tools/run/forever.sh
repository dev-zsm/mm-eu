#!/bin/bash
# Runs tools/run/daily.sh again and again, for a machine that stays on (see docs/TOOLS.md). tools/run/forever.sh [hours per round=3]
# A failed round (a check that does not pass) is thrown away so the next one starts from the last commit.
# Every round leaves a line in build/rounds.log (tools/run/status.sh shows them). A round that fails three times in a row is
# reported by the workflow of GitHub, which complains when nothing has been pushed for 7 days.
# shortcut: nothing stops it but the service or a kill, and a push that fails is only retried by the next round.
cd "$(dirname "$0")/../.."
hours="${1:-3}"
mkdir -p build
while true; do
    start=$(date +%s)
    bash tools/run/daily.sh "$hours"
    rc=$?
    [ $rc -ne 0 ] && { echo "round failed ($rc), restoring the last commit"; git reset -q --hard HEAD; }
    bash tools/run/push.sh > /dev/null 2>&1 || true   # sends what an earlier round committed while the push was not possible
    pushed=$(git rev-list --count origin/main..HEAD 2>/dev/null || echo "?")
    echo "$(date -Is) rc=$rc seconds=$(( $(date +%s) - start )) head=$(git rev-parse --short HEAD) unpushed=$pushed $(grep -m1 '^| `code`' docs/PROGRESS.md | tr -s ' ' | cut -c1-60)" >> build/rounds.log
    [ $(( $(date +%s) - start )) -lt 300 ] && sleep 600   # daily.sh refused to start or had nothing to do: do not spin
done
