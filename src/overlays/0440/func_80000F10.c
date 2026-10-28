// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000F10(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0) = 0.0f;
    M2C_FIELD(arg0, f32 *, 4) = 0.0f;
    M2C_FIELD(arg0, f32 *, 8) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0xC) = 1.0f;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
}
