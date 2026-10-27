#!/bin/bash
# Source rules every src/boot and src/code file must respect (see docs/CONTRIBUTING.md). wip/ is not checked.
# Exit status is 0 only if no rule is broken.
cd "$(dirname "$0")/.."
files=$(find src/boot src/code -name '*.c' -not -path '*/wip/*')
fail=0
rule() {  # rule <description> <extended regex>  (the last pattern excluded with `grep -v` is read from $EXCEPT)
    local hits
    hits=$(grep -nE "$2" $files | grep -vE "${EXCEPT:-^$}")
    if [ -n "$hits" ]; then echo "FAIL $1:"; echo "$hits" | head -10; fail=1; fi
}
rule "inline assembly"                       '__asm__|\basm *\(|\basm +volatile'
EXCEPT='pragma intrinsic \((sqrtf|fabsf)\)' rule "#pragma other than the sqrtf/fabsf idiom" '#pragma'
rule "reference to another project or a web address" 'https?://|zeldaret'
n=$(grep -l 'COMPILER: ido53' $files | wc -l)
echo "note: $n files are built with IDO 5.3 (each must fail with IDO 7.1, see CONTRIBUTING.md)"
[ $fail = 0 ] && echo "style: OK ($(echo "$files" | wc -l) files)"
exit $fail
