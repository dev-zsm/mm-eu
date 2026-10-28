// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, s32, u8 *, M2C_UNK);   /* extern */

s32 func_800000D8(u8 *arg0, M2C_UNK arg1) {
    if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F, arg0, arg1) != 0) {
        return 0;
    }
    return 1;
}
