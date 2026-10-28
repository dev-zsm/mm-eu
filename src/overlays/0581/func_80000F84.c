// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FF72C(s32, u8 *);                     /* extern */

s32 func_80000F84(s32 arg0, u8 *arg1) {
    u8 *var_s0;

    var_s0 = M2C_FIELD(arg1, u8 **, 0x1CD8);
    if (var_s0 != NULL) {
loop_2:
        if ((M2C_FIELD(var_s0, s16 *, 0) == 9) && (func_800FF72C(arg0 + 0x24, var_s0 + 0x24) < 500.0f) && (M2C_FIELD(var_s0, s16 *, 0x1F0) == 0)) {
            return 1;
        }
        var_s0 = M2C_FIELD(var_s0, u8 **, 0x12C);
        if (var_s0 == NULL) {
            goto block_7;
        }
        goto loop_2;
    }
block_7:
    return 0;
}
