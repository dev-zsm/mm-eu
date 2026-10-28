// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800015E0(u8 *arg0, u8 *arg1) {
    f32 temp_f0;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x2C) + 70.0f;
    if (((M2C_FIELD(arg0, s16 *, 0x1C) & 0xFF) != 1) && (M2C_FIELD(temp_v0, f32 *, 0x2C) < temp_f0)) {
        M2C_FIELD(temp_v0, f32 *, 0x2C) = temp_f0;
    }
}
