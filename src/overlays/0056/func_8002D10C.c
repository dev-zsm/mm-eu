// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8002D10C(u8 *arg0, u8 *arg1) {
    s16 temp_v0;

    M2C_FIELD(arg0, f32 *, 0x24) = (f32) M2C_FIELD(arg1, s32 *, 0xC);
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) M2C_FIELD(arg1, s32 *, 0x10);
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) M2C_FIELD(arg1, s32 *, 0x14);
    temp_v0 = M2C_FIELD(arg1, s16 *, 8);
    M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0xAD4) = temp_v0;
}
