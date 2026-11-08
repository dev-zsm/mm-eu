// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0148.h"

M2C_UNK func_80913A2C();                            /* extern */

void EnHonotrap_EyeIdle2(EnHonotrap *this, PlayState *play) {
    f32 temp_f0;
    s16 temp_v0;

    if ((M2C_FIELD(this, s16 *, 0x220) <= 0) && (M2C_FIELD(this, f32 *, 0x98) < 120.0f)) {
        temp_f0 = M2C_FIELD(this, f32 *, 0x9C);
        if ((temp_f0 < 0.0f) && (temp_f0 > -700.0f)) {
            temp_v0 = M2C_FIELD(this, s16 *, 0x92) - M2C_FIELD(this, s16 *, 0xBE);
            if ((temp_v0 >= -0x3FFF) && (temp_v0 < 0x4000)) {
                func_80913A2C();
            }
        }
    }
}
