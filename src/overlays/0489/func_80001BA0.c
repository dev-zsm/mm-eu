// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8017B9A8(u8 *, u8 *);                  /* extern */

s32 func_80001BA0(u8 *arg0, u8 *arg1, f32 arg2, s32 arg3) {
    s32 pad[2];
    s32 sp34;
    u8 *var_s0;

    var_s0 = M2C_FIELD(arg1, u8 **, 0x1D2C);
    sp34 = 0;
    if (var_s0 != NULL) {
loop_1:
        if ((M2C_FIELD(var_s0, s16 *, 0) == 5) && (M2C_FIELD(var_s0, s32 *, 0x138) != 0) && (M2C_FIELD(arg0, s8 *, 3) == M2C_FIELD(var_s0, s8 *, 3)) && (func_8017B9A8(var_s0 + 0x24, arg0 + 0x24) < arg2)) {
            M2C_FIELD(var_s0, s8 *, 0x1A7) = (s8) arg3;
            sp34 = 1;
        } else {
            var_s0 = M2C_FIELD(var_s0, u8 **, 0x12C);
            if (var_s0 != NULL) {
                goto loop_1;
            }
        }
    }
    return sp34;
}
