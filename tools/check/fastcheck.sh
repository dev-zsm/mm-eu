#!/bin/bash
# `make check` on the native disk of WSL. usage (in WSL): tools/check/fastcheck.sh [make target, default: check]
#
# A repository on the Windows disk (/mnt/c/...) is read through a slow network layer (about 10 ms per file, and the
# project has thousands of small files), so the checks take several times longer than on the native Linux disk.
# When the repository is under /mnt/, this script mirrors what the checks read to a native directory (incrementally:
# only changed files are copied) and runs make there. Nothing is ever copied back, the repository is not modified.
# Elsewhere (a native checkout, Linux, CI) it just runs make in place.
#   MM_WORK=<dir>   where the mirror lives (default: ~/.cache/mm-eu-work)
set -e
root=$(cd "$(dirname "$0")/../.." && pwd)
case "${MM_WORK:-}" in "~" | "~/"*) MM_WORK="$HOME${MM_WORK#\~}" ;; esac   # a ~ the shell did not expand: the home of WSL
bash "$root/tools/check/preflight.sh" "$root" "$HOME" || exit 1
# One fastcheck at a time on the machine, whatever the checkout: WSL has a few GB and several mirrors and compile jobs at once killed it.
# flock on a file of the home directory: the system releases it when the run ends or is killed.
exec 8> "$HOME/.mm-fastcheck.lock"
if ! flock -n 8; then
    echo "waiting for another fastcheck (held by $(cat "$HOME/.mm-fastcheck.owner" 2>/dev/null || echo '?'))"
    flock 8
fi
echo "$root" > "$HOME/.mm-fastcheck.owner"
target=${1:-check}
case "$root" in
  /mnt/*)
    work=${MM_WORK:-$HOME/.cache/mm-eu-work}
    mkdir -p "$work"
    # what the checks read: sources, configuration, headers, tools, the generated assembly and the extracted files
    # The Windows disk answers one reader slowly (about 400 files a second) and several readers faster: the folders
    # two levels down (src/overlays/<overlay>, src/code/<file>, include/generated/overlays, asm/overlays/<overlay> ...) and
    # extracted/ are copied by two rsync at a time (more made WSL run out of memory), after one rsync for everything above them. A folder that is a link to
    # another checkout (asm, extracted in a worktree) is copied as files: the checks then read it from the native disk.
    sync() { rsync -a --delete --copy-unsafe-links --exclude='.git' --exclude='/.claude' --exclude='/decomp' --exclude='baserom' \
                   --exclude='tools/vendor' --exclude='__pycache__' --exclude='/build' --exclude='wip' "$@"; }
    units=$(cd "$root" && find -H src/ include/ asm/ -mindepth 2 -maxdepth 2 -type d ! -name wip | sort)
    # a folder that left the repository (an overlay folder that got its name) must leave the mirror: the rsync above them does not look inside
    (cd "$work" && find src include asm -mindepth 2 -maxdepth 2 -type d 2>/dev/null | sort) | comm -13 <(echo "$units") - | (cd "$work" && xargs -r -d '\n' rm -rf)
    sync --exclude='/src/*/*/' --exclude='/include/*/*/' --exclude='/asm/*/*/' --exclude='/extracted/' "$root/" "$work/"
    export -f sync
    { echo "$units"; echo extracted; } | xargs -d '\n' -P 2 -I{} bash -c 'sync "$1/$3/" "$2/$3/"' _ "$root" "$work" {}
    mkdir -p "$work/build"
    cp -u "$root/build/boot.bin" "$work/build/" 2>/dev/null || true
    for s in boot code; do  # the link scripts and symbol lists written by `make split`; the objects are rebuilt in the mirror
        mkdir -p "$work/build/$s/named" "$work/build/$s/fn"
        cp -u "$root/build/$s/$s.ld" "$root"/build/$s/undefined_*.txt "$work/build/$s/" 2>/dev/null || true
    done
    [ -e "$work/tools/vendor" ] || ln -s "$root/tools/vendor" "$work/tools/vendor" 2>/dev/null || true
    cd "$work"
    ;;
  *) cd "$root" ;;
esac
make "$target"
