// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B6185C();                            /* extern */

void func_80000B08(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x30E);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x30E) = (s16) (temp_v0 - 1);
    } else {
        M2C_FIELD(arg0, f32 *, 0x300) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x304) = 0.0f;
    }
    if (M2C_FIELD(arg0, u8 *, 0x11C) == 0) {
        M2C_FIELD(arg0, s16 *, 0x30E) = 0;
        func_80B6185C();
    }
}
