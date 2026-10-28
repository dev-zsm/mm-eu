// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80010F78(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f0;

    if ((arg3 == 0.0f) && (arg1 > 0.0f)) {
        arg3 = arg2;
    }
    temp_f0 = (arg0 + arg1) - arg3;
    if (((temp_f0 * arg1) >= 0.0f) && (((temp_f0 - arg1) * arg1) < 0.0f)) {
        return 1;
    }
    return 0;
}
