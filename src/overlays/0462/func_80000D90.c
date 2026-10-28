// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_80AFAEB0(u8 *, M2C_UNK (*)(u8 *, s32), M2C_UNK, s16); /* extern */
M2C_UNK func_80AFB2D0(u8 *, s32);                 /* extern */

void func_80000D90(u8 *arg0, s32 arg1) {
    if (func_800B5B20(arg1, ((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 8) & 0x7F) == 0) {
        if ((M2C_FIELD(arg0, s16 *, 0x1C) & 7) == 1) {
            func_80AFAEB0(arg0, func_80AFB2D0, 0, M2C_FIELD(arg0, s16 *, 0x1BA));
            return;
        }
        func_80AFB2D0(arg0, arg1);
    }
}
