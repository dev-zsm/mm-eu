// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000002C(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0xAD0) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
