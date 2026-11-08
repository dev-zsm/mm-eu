// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEE3C(u8 *, f32, f32, u8 *);
void func_808D20F0();

void func_800018FC(u8 *arg0, s32 arg1) {
    f32 f;

    if (func_800FEE3C(arg0 + 0x58, 0.0f, 0.0015f, arg0) != 0) {
        func_808D20F0(arg0);
    }
    f = M2C_FIELD(arg0, f32 *, 0x58);
    M2C_FIELD(arg0, f32 *, 0x60) = f;
    M2C_FIELD(arg0, f32 *, 0x5C) = f;
}
