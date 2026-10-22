// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_8017BB44(void *arg0, void *arg1, void *arg2) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    s32 var_v1;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0);
    var_v1 = 0;
    if (M2C_FIELD(arg2, f32 *, 0) < temp_f0) {
        var_v1 = 1;
    } else if (temp_f0 < M2C_FIELD(arg1, f32 *, 0)) {
        var_v1 = 2;
    }
    temp_f0_2 = M2C_FIELD(arg0, f32 *, 4);
    if (M2C_FIELD(arg2, f32 *, 4) < temp_f0_2) {
        var_v1 |= 4;
    } else if (temp_f0_2 < M2C_FIELD(arg1, f32 *, 4)) {
        var_v1 |= 8;
    }
    temp_f0_3 = M2C_FIELD(arg0, f32 *, 8);
    if (M2C_FIELD(arg2, f32 *, 8) < temp_f0_3) {
        var_v1 |= 0x10;
    } else if (temp_f0_3 < M2C_FIELD(arg1, f32 *, 8)) {
        var_v1 |= 0x20;
    }
    return var_v1;
}
