// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000BD50(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x188C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x1890) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x1894) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x1898) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x18C0) = 0.0f;
}
