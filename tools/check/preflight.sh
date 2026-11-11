#!/bin/bash
# Refuses (exit 1) to start heavy work when a disk is nearly full: a full disk crashed WSL and every agent with it.
# usage: tools/check/preflight.sh [dir ...]     default: the repository and the home directory (the native disk of WSL: cache, mirror)
# MM_MIN_FREE_GB (default 15) is the least free space accepted. Called by tools/mm, fastcheck.sh, push.sh and forever.sh.
cd "$(dirname "$0")/../.."
min=${MM_MIN_FREE_GB:-15}
[ $# -eq 0 ] && set -- . "$HOME"
for d in "$@"; do
    free=$(df -Pk "$d" 2>/dev/null | awk 'NR==2 {print int($4 / 1048576)}')
    if [ -n "$free" ] && [ "$free" -lt "$min" ]; then
        echo "NOT ENOUGH DISK: the drive of $d has $free GB free and at least $min GB are needed. Free space first" \
             "(delete a private cache, ~/.cache/mm-eu-work*, old worktrees; the shared object cache is capped by MM_CACHE_MAX, default 8 GB)." \
             "MM_MIN_FREE_GB=<n> changes the limit." >&2
        exit 1
    fi
done
