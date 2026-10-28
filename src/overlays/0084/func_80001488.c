// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80001488(s32 arg0, s32 arg1, s32 *arg2, u8 *arg3) {
    if (arg1 == 1) {
        M2C_FIELD(arg3, f32 *, 8) = (f32) (M2C_FIELD(arg3, f32 *, 8) - 500.0f);
    }
    if ((arg1 == 7) || (arg1 == 8)) {
        *arg2 = 0;
    }
    return 0;
}
