#!/bin/bash
# Runs tools/run/daily.sh again and again, for a machine that stays on (see docs/TOOLS.md). tools/run/forever.sh [hours per round=3]
# A failed round (a check that does not pass) is thrown away so the next one starts from the last commit.
# shortcut: nothing stops it but the service or a kill, and a push that fails is only retried by the next round.
cd "$(dirname "$0")/../.."
hours="${1:-3}"
while true; do
    start=$(date +%s)
    bash tools/run/daily.sh "$hours" || { echo "round failed ($?), restoring the last commit"; git reset -q --hard HEAD; }
    bash tools/run/push.sh > /dev/null 2>&1 || true   # sends what an earlier round committed while the push was not possible
    [ $(( $(date +%s) - start )) -lt 300 ] && sleep 600   # daily.sh refused to start or had nothing to do: do not spin
done
