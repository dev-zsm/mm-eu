// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 *D_80B9E4CC;

void func_80000210(s32 arg0, M2C_UNK arg1) {
    M2C_FIELD(D_80B9E4CC, s8 *, 0x252) = (s8) (M2C_FIELD(D_80B9E4CC, s8 *, 0x252) - 1);
}
