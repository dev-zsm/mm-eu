// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0174.h"

f32 func_8017A870(f32);

void func_8000063C(Actor *thisx) {
    if (func_8017A870(1.0f) < 0.0f) {
        M2C_FIELD(thisx, u16 *, 0x3E8) |= 0x20;
    } else {
        M2C_FIELD(thisx, u16 *, 0x3E8) &= 0xFFDF;
    }
}
