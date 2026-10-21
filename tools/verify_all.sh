#!/bin/bash
# Full verification of a segment, to run in WSL:  tools/verify_all.sh boot
# 1. every src/<seg>/func_*.c compiles with IDO 7.1 to exactly the ROM bytes of that function
# 2. the whole segment, rebuilt from those C files + the remaining assembly, is byte-identical to the ROM
# Exit status is 0 only if both hold.
set -e
seg=${1:-boot}
cd "$(dirname "$0")/.."
. ~/mm-venv/bin/activate
case $seg in
  boot) orig=build/boot.bin ;;
  code) orig=extracted/0049_00C8A000.bin ;;
  *) echo "unknown segment $seg"; exit 2 ;;
esac
python3 tools/verify_src.py "$seg" | tee /tmp/verify_src.out | head -3
! grep -q FAIL /tmp/verify_src.out
python3 tools/build_seg.py "$seg" "$orig"
