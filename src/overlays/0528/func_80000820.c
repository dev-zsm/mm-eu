// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B70A4(u8 *, M2C_UNK, M2C_UNK);        /* extern */
s32 func_800B7164(u8 *, M2C_UNK);                 /* extern */

s32 func_80000820(u8 *arg0, M2C_UNK arg1) {
    if ((func_800B70A4(arg0, 0x3000, arg1) != 0) && (func_800B7164(arg0, 0x3000) != 0) && (M2C_FIELD(arg0, f32 *, 0x98) < 100.0f)) {
        return 1;
    }
    return 0;
}
