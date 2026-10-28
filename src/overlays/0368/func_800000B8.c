// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8017B984();                                /* extern */
extern f32 D_80A69284;

s32 func_800000B8(u8 *arg0, u8 *arg1, f32 *arg2, f32 *arg3) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = func_8017B984();
    if (temp_f0 < D_80A69284) {
        return 0;
    }
    temp_f2 = 1.0f / temp_f0;
    M2C_FIELD(arg1, f32 *, 0) = (f32) (M2C_FIELD(arg0, f32 *, 0) * temp_f2);
    M2C_FIELD(arg1, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 4) * temp_f2);
    M2C_FIELD(arg1, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) * temp_f2);
    *arg2 = temp_f0;
    *arg3 = temp_f2;
    return 1;
}
