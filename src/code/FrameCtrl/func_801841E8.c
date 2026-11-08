// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 FrameCtrl_PassCheck(struct FrameControl *frameCtrl, f32 t, f32 *remainingTime) {
    f32 temp_f0;
    f32 temp_f14;
    f32 var_f2;
    f32 var_f2_2;

    *remainingTime = 0.0f;
    temp_f0 = M2C_FIELD(frameCtrl, f32 *, 0x10);
    if (t == temp_f0) {
        return 0;
    }
    if (M2C_FIELD(frameCtrl, f32 *, 0) < M2C_FIELD(frameCtrl, f32 *, 4)) {
        var_f2 = M2C_FIELD(frameCtrl, f32 *, 0xC);
    } else {
        var_f2 = -M2C_FIELD(frameCtrl, f32 *, 0xC);
    }
    temp_f14 = var_f2 * 1.5f;
    if (((temp_f14 >= 0.0f) && (temp_f0 < t) && (var_f2_2 = temp_f0 + temp_f14, (t <= var_f2_2))) || ((temp_f14 < 0.0f) && (t < temp_f0) && (var_f2_2 = temp_f0 + temp_f14, (var_f2_2 <= t)))) {
        *remainingTime = var_f2_2 - t;
        return 1;
    }
    return 0;
}
