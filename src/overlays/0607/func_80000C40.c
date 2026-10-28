// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800C973C(s32, s32, u8, u8 *);            /* extern */

s32 func_80000C40(u8 *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_800C973C(arg1 + 0x830, M2C_FIELD(arg0, s32 *, 0x80), M2C_FIELD(arg0, u8 *, 0x85), arg0);
    var_v1 = temp_v0;
    if ((temp_v0 < 4) || (temp_v0 >= 0x13)) {
        var_v1 = -1;
    }
    return var_v1;
}
