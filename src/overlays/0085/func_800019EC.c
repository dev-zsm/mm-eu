// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800019EC(u8 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (((((s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0x1C0) >> 6) & 0xFF) == 1) && (M2C_FIELD(arg0, u8 *, 0xB7) != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}
