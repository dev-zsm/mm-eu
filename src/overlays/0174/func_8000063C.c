// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8017A870(f32);

void func_8000063C(u8 *arg0) {
    if (func_8017A870(1.0f) < 0.0f) {
        M2C_FIELD(arg0, u16 *, 0x3E8) |= 0x20;
    } else {
        M2C_FIELD(arg0, u16 *, 0x3E8) &= 0xFFDF;
    }
}
