#!/bin/bash
# Refuses (exit 1) to start heavy work when a disk is nearly full or MM_WORK is not a path of WSL: a full disk crashed WSL.
# usage: tools/check/preflight.sh [dir ...]     default: the repository and the home directory (the native disk of WSL: cache, mirror)
# MM_MIN_FREE_GB (default 15) is the least free space accepted. Called by tools/mm, fastcheck.sh, push.sh and forever.sh.
# MM_WORK (the mirror of fastcheck.sh) must be an absolute path of WSL, in its home: `~/x` that the shell did not expand, a Windows path
# (C:\\x), a Git Bash path (/c/x) or a relative one created a folder named `~` or failed with `mkdir: Permission denied`.
cd "$(dirname "$0")/../.."
if [ -n "${MM_WORK:-}" ]; then
    case "$MM_WORK" in
        "~"* | [A-Za-z]:* | /[a-z] | /[a-z]/* | [!/]*)
            if [[ "$MM_WORK" == "~"* ]] || [[ "$(uname -s)" == MINGW* ]] || [ ! -d "$MM_WORK" ]; then
                echo "MM_WORK=$MM_WORK is not an absolute path of WSL (a quoted ~, a Windows or Git Bash path, or a relative one): use MM_WORK=/home/<user>/work_x" >&2
                exit 1
            fi ;;
    esac
fi
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
