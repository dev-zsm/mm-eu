// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80001B14(s32 arg0, u8 *arg1) {
    M2C_FIELD(arg1, s16 *, 0xB28) = 0;
    M2C_FIELD(arg1, f32 *, 0xB0C) = 1.0f;
}
