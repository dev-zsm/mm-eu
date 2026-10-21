// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80085260(u8 *a0, s32 a1, s32 a2) {
    *(u8 *)(a0 + 0x14) = a1;
    *(u8 *)(a0 + 0x15) = a2;
}
