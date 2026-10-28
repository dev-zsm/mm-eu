// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BAE44(s32, u8 *, s32, M2C_UNK, f32, f32, f32, s32, s32, s32, s32); /* extern */

void func_80001AB0(u8 *arg0, s32 arg1) {
    func_800BAE44(arg1 + 0x1CA0, arg0, arg1, 0x200, M2C_FIELD(arg0, f32 *, 8), M2C_FIELD(arg0, f32 *, 0xC), M2C_FIELD(arg0, f32 *, 0x10), 0, 0, 0, 0x40);
}
