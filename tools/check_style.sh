#!/bin/bash
# Source rules every file of src/boot, src/code and src/overlays must respect (see docs/CONTRIBUTING.md). wip/ is not checked.
# Exit status is 0 only if no rule is broken. The rules are in tools/check_style.py (one pass over the files).
exec python3 "$(dirname "$0")/check_style.py"
