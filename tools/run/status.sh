#!/bin/bash
# What the unattended runs have done. usage: tools/run/status.sh [rounds to show=8]
# On the machine that runs tools/run/forever.sh: the service, the last rounds, the commits that are not pushed yet, the load.
cd "$(dirname "$0")/../.."
n="${1:-8}"
echo "service:  $(systemctl is-active mm-eu 2>/dev/null || echo 'not a systemd machine')"
echo "load:     $(cut -d' ' -f1-3 /proc/loadavg)"
echo "head:     $(git log -1 --format='%h %ar %s')"
echo "unpushed: $(git rev-list --count origin/main..HEAD 2>/dev/null)"
echo "rounds:"
[ -f build/rounds.log ] && tail -n "$n" build/rounds.log | sed 's/^/  /' || echo "  none yet"
