#include "types.h"
#include "m2c_compat.h"

s32 func_80000B5C(u8 *arg0) {
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;
    f32 temp_f2_2;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0x28);
    temp_f2 = temp_f0 + 2.0f;
    temp_f12 = M2C_FIELD(arg0, f32 *, 0x3F0);
    if (temp_f2 < temp_f12) {
        M2C_FIELD(arg0, f32 *, 0x28) = temp_f2;
        return 0;
    }
    temp_f2_2 = temp_f0 - 2.0f;
    if (temp_f12 < temp_f2_2) {
        M2C_FIELD(arg0, f32 *, 0x28) = temp_f2_2;
        return 0;
    }
    return 1;
}
