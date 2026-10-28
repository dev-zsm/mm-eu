// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80001FE8(u8 *arg0, u8 *arg1, f32 arg2) {
    f32 temp_f0;
    f32 temp_f2;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    M2C_FIELD(temp_v0, s16 *, 0xBE) = (s16) (M2C_FIELD(temp_v0, s16 *, 0xBE) + 0x2EE0);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x1E90);
    M2C_FIELD(temp_v0, f32 *, 0x58) = (f32) (((0.0f - temp_f0) * arg2) + temp_f0);
    temp_f2 = M2C_FIELD(arg0, f32 *, 0x1E94);
    M2C_FIELD(temp_v0, f32 *, 0x60) = (f32) (((0.0f - temp_f2) * arg2) + temp_f2);
}
