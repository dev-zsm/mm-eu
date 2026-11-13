#!/bin/bash
# Push the local commits. In WSL:  tools/run/push.sh
# Several machines may run tools/run/forever.sh on the same repository. When the push is refused because another one pushed first,
# the local commits go on top of the new origin/main (on a conflict the other side wins), the whole tree is checked again against
# the ROM and the progress counters are refreshed. If that does not work out, the local commits are dropped and the next round redoes them.
cd "$(dirname "$0")/../.."
[ -n "${NO_PUSH:-}" ] && exit 0
for try in 1 2 3; do
    git push -q 2>/dev/null && exit 0
    git fetch -q || exit 1
    python3 tools/run/clear_untracked.py origin/main   # files a failed round left untracked that origin/main has now stop the rebase
    if ! python3 tools/run/rebase_ours.py origin/main; then
        git rebase --abort 2>/dev/null
        git reset -q --hard origin/main
        echo "rebase failed, local commits dropped"; exit 1
    fi
    if ! bash tools/search/wave_finish.sh > /dev/null 2>&1; then
        git reset -q --hard origin/main
        echo "the merged tree does not check, local commits dropped"; exit 1
    fi
    git add README.md docs/PROGRESS.md
    git diff --cached --quiet || git commit -q --amend --no-edit
done
exit 1
