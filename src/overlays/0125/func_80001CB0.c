// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0125.h"

void func_80001CB0(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x38C) = 0.75f;
    M2C_FIELD(arg0, f32 *, 0x390) = 1.125f;
    M2C_FIELD(arg0, f32 *, 0x388) = 1.0f;
    M2C_FIELD(arg0, u8 *, 0x2B5) = 0xA;
    M2C_FIELD(arg0, u8 *, 0x640) = 3;
    M2C_FIELD(arg0, u8 *, 0x658) = 0;
    M2C_FIELD(arg0, s16 *, 0x2BE) = 2;
    M2C_FIELD(arg0, s32 *, 4) &= ~0x200;
}
