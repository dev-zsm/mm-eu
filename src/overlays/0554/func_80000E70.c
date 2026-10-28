// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8013DD10(s32, s32, M2C_UNK, M2C_UNK);      /* extern */

s32 func_80000E70(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_8013DD10(arg1, M2C_FIELD(arg0, s32 *, 0x144), 4, 0x213);
    M2C_FIELD(arg0, s32 *, 0x144) = temp_v0;
    if (temp_v0 != 0) {
        return 1;
    }
    return 0;
}
