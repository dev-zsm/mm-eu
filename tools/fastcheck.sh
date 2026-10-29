#!/bin/bash
# `make check` on the native disk of WSL. usage (in WSL): tools/fastcheck.sh [make target, default: check]
#
# A repository on the Windows disk (/mnt/c/...) is read through a slow network layer (about 10 ms per file, and the
# project has thousands of small files), so the checks take several times longer than on the native Linux disk.
# When the repository is under /mnt/, this script mirrors what the checks read to a native directory (incrementally:
# only changed files are copied) and runs make there. Nothing is ever copied back, the repository is not modified.
# Elsewhere (a native checkout, Linux, CI) it just runs make in place.
#   MM_WORK=<dir>   where the mirror lives (default: ~/.cache/mm-eu-work)
set -e
root=$(cd "$(dirname "$0")/.." && pwd)
target=${1:-check}
case "$root" in
  /mnt/*)
    work=${MM_WORK:-$HOME/.cache/mm-eu-work}
    mkdir -p "$work"
    # what the checks read: sources, configuration, headers, tools, the generated assembly and the extracted files
    rsync -a --delete --exclude='.git' --exclude='baserom' --exclude='tools/vendor' --exclude='tools/__pycache__' \
          --exclude='/build' --exclude='src/*/wip' --exclude='src/overlays/*/wip' "$root/" "$work/"
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
