// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80001014(u8 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (M2C_FIELD(arg0, f32 *, 0x2C8) > 0.0f) {
        if ((M2C_FIELD(arg0, f32 *, 0xC) - 10.0f) < M2C_FIELD(arg0, f32 *, 0x28)) {
            goto block_4;
        }
    } else if (M2C_FIELD(arg0, f32 *, 0x28) < (M2C_FIELD(arg0, f32 *, 0x88) + 20.0f)) {
block_4:
        var_v1 = 1;
    }
    return var_v1;
}
