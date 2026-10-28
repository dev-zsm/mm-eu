// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000174(u8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (500.0f * arg1);
}
