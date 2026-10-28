// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 *D_801EB7E0;

void func_80000264(s32 arg0, M2C_UNK arg1, u8 *arg2) {
    if ((M2C_FIELD(arg2, s16 *, 0x5C) == 6) && (M2C_FIELD(arg2, s16 *, 0x40) != 0)) {
        M2C_FIELD(D_801EB7E0, s16 *, 0xD38) = 0;
    }
}
