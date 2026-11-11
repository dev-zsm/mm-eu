#!/bin/bash
# Copies asm/ from another checkout instead of running `make split` (about 30 minutes of disassembly, and on a small VPS (3.8 GB RAM)
# it made the machine unreachable). usage: tools/run/sync_asm.sh <checkout>   a path, or user@host:/path/to/checkout over ssh
# The source must be a checkout whose asm/ comes from the same `make split` as this one (same config/ and extracted/).
src=${1:?usage: tools/run/sync_asm.sh <checkout | user@host:/path/to/checkout>}
cd "$(dirname "$0")/../.."
bash tools/check/preflight.sh . || exit 1
rsync -a --delete -e "ssh -o BatchMode=yes" "${src%/}/asm/" asm/ || exit 1
echo "asm/ copied from $src: $(find asm -name text.s | wc -l) text.s files"
