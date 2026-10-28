// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B9B79C;

void func_800001F0(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80B9B79C;
    M2C_FIELD(arg0, f32 *, 0x160) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x15C) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0x1A4) = 0x19;
    M2C_FIELD(arg0, s16 *, 0x1A6) = 0x2E;
    M2C_FIELD(arg0, s16 *, 0x1A8) = -0x17;
    M2C_FIELD(arg0, s8 *, 0x158) = 0;
}
