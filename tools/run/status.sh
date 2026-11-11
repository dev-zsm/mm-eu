#!/bin/bash
# What the unattended runs have done. usage: tools/run/status.sh [rounds to show=8]
# On the machine that runs tools/run/forever.sh: the service, the last rounds, the commits that are not pushed yet, the load.
# Prints an ALERT line when no round ended with rc=0 for 24 hours, or the disk is nearly full.
cd "$(dirname "$0")/../.."
n="${1:-8}"
echo "service:  $(systemctl is-active mm-eu 2>/dev/null || echo 'not a systemd machine')"
echo "load:     $(cut -d' ' -f1-3 /proc/loadavg)"
echo "head:     $(git log -1 --format='%h %ar %s')"
echo "unpushed: $(git rev-list --count origin/main..HEAD 2>/dev/null)"
echo "rounds:"
[ -f build/rounds.log ] && tail -n "$n" build/rounds.log | sed 's/^/  /' || echo "  none yet"
last=$(grep -a ' rc=0 ' build/rounds.log 2>/dev/null | tail -n 1 | cut -d' ' -f1)
age=$(( $(date +%s) - $(date -d "${last:-@0}" +%s 2>/dev/null || echo 0) ))
[ -f build/rounds.log ] && [ "$age" -gt 86400 ] && echo "ALERT: no round ended with rc=0 since ${last:-the start} ($((age / 3600)) hours)"
bash tools/check/preflight.sh 2>&1 | sed 's/^/ALERT: /'
exit 0
