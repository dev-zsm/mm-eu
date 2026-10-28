// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80913A2C();                            /* extern */

void func_80000980(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f0;
    s16 temp_v0;

    if ((M2C_FIELD(arg0, s16 *, 0x220) <= 0) && (M2C_FIELD(arg0, f32 *, 0x98) < 120.0f)) {
        temp_f0 = M2C_FIELD(arg0, f32 *, 0x9C);
        if ((temp_f0 < 0.0f) && (temp_f0 > -700.0f)) {
            temp_v0 = M2C_FIELD(arg0, s16 *, 0x92) - M2C_FIELD(arg0, s16 *, 0xBE);
            if ((temp_v0 >= -0x3FFF) && (temp_v0 < 0x4000)) {
                func_80913A2C();
            }
        }
    }
}
