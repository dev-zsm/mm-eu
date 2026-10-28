// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1D6C(s16);                         /* extern */
s16 func_800F1E68(s16);                             /* extern */
s32 func_800F1F28(s16);                             /* extern */

s32 func_80001454(u8 *arg0, u8 *arg1) {
    u8 *var_s0;

    var_s0 = M2C_FIELD(arg1, u8 **, 0x1CE4);
    if (var_s0 != NULL) {
loop_1:
        if ((M2C_FIELD(var_s0, s16 *, 0) == 0x1EE) && (func_800F1F28(M2C_FIELD(arg0, s16 *, 0x430)) == M2C_FIELD(var_s0, s32 *, 0x1E8))) {
            func_800F1D6C(M2C_FIELD(arg0, s16 *, 0x430));
            M2C_FIELD(arg0, u8 **, 0x3F4) = var_s0;
            M2C_FIELD(arg0, s16 *, 0x430) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x430));
            return 1;
        }
        var_s0 = M2C_FIELD(var_s0, u8 **, 0x12C);
        if (var_s0 == NULL) {
            goto block_5;
        }
        goto loop_1;
    }
block_5:
    return 0;
}
