// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800020D8(u8 *arg0) {
    s32 temp_v0_2;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x730);
    if ((temp_v0 != NULL) && ((M2C_FIELD(temp_v0, s32 *, 4) & 5) == 5)) {
        M2C_FIELD(arg0, s32 *, 0xA74) = (s32) (M2C_FIELD(arg0, s32 *, 0xA74) | 0x80000000);
        return 1;
    }
    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0xA74);
    if (temp_v0_2 & 0x80000000) {
        M2C_FIELD(arg0, s32 *, 0xA74) = (s32) (temp_v0_2 & 0x7FFFFFFF);
        if (M2C_FIELD(arg0, f32 *, 0xAD0) == 0.0f) {
            M2C_FIELD(arg0, s16 *, 0xAD4) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
        }
    }
    return 0;
}
