// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000294(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x2AC) = 0xA;
    M2C_FIELD(arg0, s8 *, 0x398) = 3;
    M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x3A0), s8 *, 0x14) = 0;
    M2C_FIELD(arg0, f32 *, 0x2C8) = 0.75f;
    M2C_FIELD(arg0, f32 *, 0x2CC) = 1.125f;
    M2C_FIELD(arg0, f32 *, 0x2C4) = 1.0f;
}
