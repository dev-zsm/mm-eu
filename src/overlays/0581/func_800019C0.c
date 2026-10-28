// FLAGS: -O1 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern s8 D_801EAE45;

void func_800019C0(s32 arg0, u8 *arg1) {
    M2C_FIELD(arg1, s16 *, 0x1887A) = 0x2020;
    M2C_FIELD(arg1, s8 *, 0x18875) = 0x14;
    M2C_FIELD(arg1, s8 *, 0x1887F) = 0x46;
    D_801EAE45 = 2;
}
