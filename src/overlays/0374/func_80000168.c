// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

u8 *func_8013DD10(M2C_UNK, s32, M2C_UNK, M2C_UNK); /* extern */

s32 func_80000168(s32 arg0, M2C_UNK arg1) {
    s32 pad;
    s32 sp28;
    s32 var_s0;
    u8 *temp_v0;

    sp28 = 0;
    var_s0 = 0;
loop_1:
    temp_v0 = func_8013DD10(arg1, var_s0, 8, 0x1A5);
    if ((temp_v0 != NULL) && ((M2C_FIELD(temp_v0, s16 *, 0x1C) & 0xF) == 1) && !(M2C_FIELD(temp_v0, s32 *, 0x16C) & 1)) {
        sp28 = 1;
    } else {
        var_s0 = M2C_FIELD(temp_v0, s32 *, 0x12C);
        if (var_s0 != 0) {
            goto loop_1;
        }
    }
    return sp28;
}
