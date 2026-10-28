// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(u8 *, f32, M2C_UNK);        /* extern */
M2C_UNK func_80968C5C(u8 *, s32);                 /* extern */
M2C_UNK func_8096A01C(u8 *);                      /* extern */

void func_800018F8(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    func_800FEE3C(arg0 + 0x24, M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x120), f32 *, 0x24), 0x41200000);
    func_800FEE3C(arg0 + 0x2C, M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x120), f32 *, 0x2C), 0x41200000);
    func_800FEE3C(arg0 + 0x28, M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x120), f32 *, 0x28) + 80.0f, 0x41200000);
    func_800FEE3C(arg0 + 0x58, 0.15f, 0x3BF5C290);
    func_800FEE3C(arg0 + 0x5C, 0.075f, 0x3B75C290);
    func_800FEE3C(arg0 + 0x60, 0.15f, 0x3BF5C290);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    if (temp_v0 == 0xB) {
        func_8096A01C(arg0);
        return;
    }
    if (temp_v0 == 3) {
        func_80968C5C(arg0, arg1);
    }
}
