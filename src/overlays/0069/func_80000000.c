// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000000(s32 arg0, u32 arg1, u8 *arg2) {
    u8 *temp_v0;

    temp_v0 = arg0 + (arg1 * 0xA);
    M2C_FIELD(arg2, f32 *, 0) = (f32) M2C_FIELD(temp_v0, s16 *, 0);
    M2C_FIELD(arg2, f32 *, 4) = (f32) M2C_FIELD(temp_v0, s16 *, 2);
    M2C_FIELD(arg2, f32 *, 8) = (f32) M2C_FIELD(temp_v0, s16 *, 4);
}
