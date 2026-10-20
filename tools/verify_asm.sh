#!/bin/bash
# Reassemble the splat output of one segment and check it is byte-identical to the ROM file.
# usage (in WSL): tools/verify_asm.sh <boot|code> <original.bin>
set -e
n=$1; orig=$2
cd "$(dirname "$0")/.."
AS="mips-linux-gnu-as -march=vr4300 -mabi=32 -EB -Iinclude -G0 --defsym __ASSEMBLER__=1"
for s in $(cd . && find asm/$n -name '*.s'); do
  mkdir -p "build/$n/$(dirname "$s")"
  $AS "$s" -o "build/$n/$s.o"
done
mips-linux-gnu-ld -EB -T build/$n/$n.ld -T build/$n/undefined_syms_auto.txt -T build/$n/undefined_funcs_auto.txt \
  --no-check-sections -o build/$n/$n.elf
mips-linux-gnu-objcopy -O binary build/$n/$n.elf build/$n/$n.rebuilt.bin
if cmp -s build/$n/$n.rebuilt.bin "$orig"; then echo "$n: IDENTICAL ($(stat -c%s "$orig") bytes)"; else echo "$n: DIFFERENT"; cmp build/$n/$n.rebuilt.bin "$orig" | head -3; exit 1; fi
