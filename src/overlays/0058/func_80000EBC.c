// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000EBC(s32 arg0, u8 *arg1) {
    M2C_FIELD(arg1, s16 *, 0x1A0) = 1;
    M2C_FIELD(arg1, s32 *, 0x13C) = 0;
}
