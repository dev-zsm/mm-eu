// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800006AC(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x20) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x1C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x18) = 0.0f;
}
