// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AFA798;

void func_800002BC(u8 *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x1B4) = arg1;
    M2C_FIELD(arg0, s16 *, 0x1BC) = arg2;
    M2C_FIELD(arg0, M2C_UNK **, 0x1AC) = &D_80AFA798;
}
