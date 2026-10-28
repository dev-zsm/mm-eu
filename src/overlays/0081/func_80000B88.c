// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6FD0(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_800F1E2C();                                /* extern */
s32 func_800FEE3C(u8 *, f32, M2C_UNK);            /* extern */

s32 func_80000B88(u8 *arg0, s32 arg1, f32 arg2) {
    if ((1.0f - arg2) == M2C_FIELD(arg0, f32 *, 0x168)) {
        if (arg2 == 1.0f) {
            func_800B8C4C(arg0, 0x285A);
        } else {
            func_800B8C4C(arg0, 0x2859);
        }
        if ((M2C_FIELD(arg0, s16 *, 0x160) != -1) && (func_800F1E2C() == M2C_FIELD(arg0, s16 *, 0x160))) {
            func_800B6FD0(arg1, arg0, 1);
        }
    }
    if (func_800FEE3C(arg0 + 0x168, arg2, 0x3E4CCCCD) != 0) {
        return 1;
    }
    return 0;
}
