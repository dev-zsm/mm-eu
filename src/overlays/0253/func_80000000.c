// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000000(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x14C) = arg1;
    M2C_FIELD(arg0, s8 *, 0x14A) = 0;
}
