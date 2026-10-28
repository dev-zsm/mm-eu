// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8017B9A8(u8 *, s32);                     /* extern */
extern f32 D_8091DB6C;

s32 func_80000778(s32 arg0, u8 *arg1) {
    f32 temp_f20;
    u8 *var_s0;

    var_s0 = M2C_FIELD(arg1, u8 **, 0x1CC0);
    if (var_s0 != NULL) {
        temp_f20 = D_8091DB6C;
loop_2:
        if ((M2C_FIELD(var_s0, s16 *, 0) == 0xD) && (func_8017B9A8(var_s0 + 0x24, arg0 + 0x24) < temp_f20)) {
            return 1;
        }
        var_s0 = M2C_FIELD(var_s0, u8 **, 0x12C);
        if (var_s0 == NULL) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    return 0;
}
