#!/bin/bash
# One-line alert for a machine that runs tools/run/forever.sh: when no round ended with rc=0 for 24 hours, `build/ALERT` holds
# one line saying so (removed when a round passes again), the line goes to the system log once (`logger -p user.crit`) and is printed.
# Nothing is sent outside the machine. Called by forever.sh after every round and by status.sh (which prints it first).
cd "$(dirname "$0")/../.."
[ -f build/rounds.log ] || exit 0
last=$(grep -a ' rc=0 ' build/rounds.log | tail -n 1 | cut -d' ' -f1)
age=$(( $(date +%s) - $(date -d "${last:-@0}" +%s 2> /dev/null || echo 0) ))
if [ "$age" -gt 86400 ]; then
    msg="ALERT: no round ended with rc=0 since ${last:-the start} (more than 24 hours)"
    if [ "$(cat build/ALERT 2> /dev/null)" != "$msg" ]; then   # the same line is logged once
        echo "$msg" > build/ALERT
        logger -p user.crit -t mm-eu "$msg" 2> /dev/null || true
    fi
    echo "$msg"
else
    rm -f build/ALERT
fi
exit 0
