// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_80A556F4(u8 *, s32);                 /* extern */

void func_800002AC(u8 *arg0, s32 arg1) {
    if (func_800B5B20(arg1, ((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 4) & 0x7F) != 0) {
        func_80A556F4(arg0, arg1);
    }
}
