// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8017B9A8(u8 *, s32, u8 *);             /* extern */

s32 func_80000000(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 0x16D) & 2) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x164);
        if ((temp_v0 != 0) && (func_8017B9A8(arg0 + 0x24, temp_v0 + 0x24, arg0) < 6400.0f)) {
            return 1;
        }
    }
    return 0;
}
