#!/bin/bash
# Verify every verified C function of the overlays against the ROM, in one process and with a verdict cache. Run in WSL.
set -e
cd "$(dirname "$0")/.."
. ~/mm-venv/bin/activate
python3 tools/verify_src.py overlays | tee /tmp/verify_overlays.out | head -3
! grep -q FAIL /tmp/verify_overlays.out
