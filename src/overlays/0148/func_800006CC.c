// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8091378C();                            /* extern */
extern f32 D_8091500C;

void func_800006CC(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f0;
    s16 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x124) != 0) {
        M2C_FIELD(arg0, s16 *, 0x220) = 0xC8;
        return;
    }
    if ((M2C_FIELD(arg0, s16 *, 0x220) <= 0) && (M2C_FIELD(arg0, f32 *, 0x98) < D_8091500C)) {
        temp_f0 = M2C_FIELD(arg0, f32 *, 0x9C);
        if ((temp_f0 < 0.0f) && (temp_f0 > -700.0f)) {
            temp_v0 = M2C_FIELD(arg0, s16 *, 0x92) - M2C_FIELD(arg0, s16 *, 0xBE);
            if ((temp_v0 >= -0x3FFF) && (temp_v0 < 0x4000)) {
                func_8091378C();
            }
        }
    }
}
