// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, u8, M2C_UNK);            /* extern */
extern f32 D_808B7A30;

s32 func_80000100(u8 *arg0, M2C_UNK arg1) {
    if (func_800B5B20(arg1, M2C_FIELD(arg0, u8 *, 0x15D), arg1) == 0) {
        M2C_FIELD(arg0, f32 *, 0x58) = (f32) D_808B7A30;
    }
    return 1;
}
