// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800FEE3C(u8 *, f32, f32);
s32 func_80137070();
void func_8089A0D0();

void func_80002044(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        func_800FEE3C(arg0 + 0x70, 0.0f, 0.5f);
    }
    if (func_80137070(arg0 + 0x144) != 0) {
        func_8089A0D0(arg0, arg1);
    }
}
