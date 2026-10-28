// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern s8 D_801EACC4;

s32 func_800003F4(s32 arg0, M2C_UNK arg1) {
    D_801EACC4 = 0;
    return 1;
}
