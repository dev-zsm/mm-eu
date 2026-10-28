// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80ACEDE4();                            /* extern */

void func_80000550(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x354);
    if (temp_v0 < 0x28) {
        M2C_FIELD(arg0, s16 *, 0x354) = (s16) (temp_v0 + 1);
        return;
    }
    if (M2C_FIELD(arg0, f32 *, 0x98) < 100.0f) {
        func_80ACEDE4();
    }
}
