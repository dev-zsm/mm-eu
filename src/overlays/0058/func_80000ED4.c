// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808640E8;

void func_80000ED4(s32 arg0, u8 *arg1) {
    M2C_FIELD(arg1, s16 *, 0x1A0) = 0;
    M2C_FIELD(arg1, M2C_UNK **, 0x13C) = &D_808640E8;
}
