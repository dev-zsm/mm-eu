// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 FrameCtrl_PassCheck(void *arg0, f32 arg1, f32 *arg2) {
    f32 temp_f0;
    f32 temp_f14;
    f32 var_f2;
    f32 var_f2_2;

    *arg2 = 0.0f;
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x10);
    if (arg1 == temp_f0) {
        return 0;
    }
    if (M2C_FIELD(arg0, f32 *, 0) < M2C_FIELD(arg0, f32 *, 4)) {
        var_f2 = M2C_FIELD(arg0, f32 *, 0xC);
    } else {
        var_f2 = -M2C_FIELD(arg0, f32 *, 0xC);
    }
    temp_f14 = var_f2 * 1.5f;
    if (((temp_f14 >= 0.0f) && (temp_f0 < arg1) && (var_f2_2 = temp_f0 + temp_f14, (arg1 <= var_f2_2))) || ((temp_f14 < 0.0f) && (arg1 < temp_f0) && (var_f2_2 = temp_f0 + temp_f14, (var_f2_2 <= arg1)))) {
        *arg2 = var_f2_2 - arg1;
        return 1;
    }
    return 0;
}
