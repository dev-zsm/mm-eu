// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

float fabsf(float);
#pragma intrinsic (fabsf)

void func_808F0DBC();

void func_8000049C(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x98) < 200.0f && fabsf(M2C_FIELD(arg0, f32 *, 0x9C)) < 30.0f) {
        func_808F0DBC();
    }
}
