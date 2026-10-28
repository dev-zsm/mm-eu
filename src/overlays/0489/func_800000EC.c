// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern s32 D_801E7D88;

s32 func_800000EC(void) {
    return D_801E7D88 & 0xFF;
}
