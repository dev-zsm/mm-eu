// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800C973C(u8 *, s32, u8, u8 *);         /* extern */

s32 func_80001788(u8 *arg0) {
    s32 var_v1;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x1CCC);
    if (func_800C973C(arg0 + 0x830, M2C_FIELD(temp_v0, s32 *, 0x80), M2C_FIELD(temp_v0, u8 *, 0x85), arg0) == 0x15) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}
