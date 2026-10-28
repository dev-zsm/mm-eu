// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s16);                        /* extern */
M2C_UNK func_808742A8(u8 *, s32);                 /* extern */

void func_8000115C(u8 *arg0, s32 arg1) {
    if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x190)) != 0) {
        func_808742A8(arg0, arg1);
        M2C_FIELD(arg0, s16 *, 0x18E) = 0x51;
    }
}
