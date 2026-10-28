// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800005C4(u8 *arg0, s32 arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1D0) + (arg1 * 6);
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) M2C_FIELD(temp_v0, s16 *, 0);
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) M2C_FIELD(temp_v0, s16 *, 2);
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) M2C_FIELD(temp_v0, s16 *, 4);
}
