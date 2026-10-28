// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s32);                        /* extern */

s32 func_800003DC(u8 *arg0, s32 arg1) {
    s32 var_s0;

    var_s0 = 0;
    if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F) == 0) {
        var_s0 = 1;
    }
    if ((func_800B5B20(arg1, (M2C_FIELD(arg0, s16 *, 0x1C) + 1) & 0x7F) != 0) && (func_800B5B20(arg1, (M2C_FIELD(arg0, s16 *, 0x1C) + 2) & 0x7F) != 0) && (func_800B5B20(arg1, (M2C_FIELD(arg0, s16 *, 0x1C) + 3) & 0x7F) != 0)) {
        var_s0 += 2;
    }
    return var_s0;
}
