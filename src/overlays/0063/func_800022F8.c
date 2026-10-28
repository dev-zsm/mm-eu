// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8086B7EC();                            /* extern */

void func_800022F8(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2B6);
    M2C_FIELD(arg0, s8 *, 0x11C) = 0x10;
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x2B6) = (s16) (temp_v0 - 1);
        if (M2C_FIELD(arg0, s16 *, 0x2B6) == 0) {
            func_8086B7EC();
        }
    }
}
