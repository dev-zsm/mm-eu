// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800B6AB0();
void func_800FF30C();
extern u8 D_808ACA98;

void func_800009FC(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1E4) = func_800B6AB0(arg0, arg0 + 0x200);
    func_800FF30C(arg0 + 0x1F4, arg0 + 0x200);
    M2C_FIELD(arg0, u8 **, 0x1D0) = &D_808ACA98;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
