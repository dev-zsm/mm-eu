// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 *D_80096D80;

void func_80083F10(s32 a0) {
    *(u8 *)((s32)D_80096D80 + 0x35) = a0;
}
