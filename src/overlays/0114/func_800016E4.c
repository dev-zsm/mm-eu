// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808D8BA0(u8 *, s32, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_808D9470();                            /* extern */

void func_800016E4(u8 *arg0, s32 arg1) {
    func_808D9470();
    M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
    M2C_FIELD(arg0, f32 *, 0x44C) = 10.0f;
    func_808D8BA0(arg0, arg1, 0, 0, 0);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x44C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x450) = 1.0f;
}
