// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80000E38(s32 arg0, M2C_UNK arg1, u8 *arg2, M2C_UNK arg3) {
    s32 var_v1;

    var_v1 = 0;
    if ((M2C_FIELD(arg2, s16 *, 0x1C) & 0xF) == 8) {
        var_v1 = 1;
    }
    return var_v1;
}
