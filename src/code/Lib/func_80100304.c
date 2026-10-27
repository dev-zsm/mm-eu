// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u32 D_801EFA00[];

u32 func_80100304(s32 arg0) {
    return D_801EFA00[(u32)(arg0 * 0x10) >> 28] + (arg0 & 0xFFFFFF) + 0x80000000;
}
