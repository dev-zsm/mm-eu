// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B273C(s32, u8 *, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_800FEE3C(u8 *, f32, M2C_UNK);            /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_808F0F38(u8 *);                      /* extern */

void func_80000578(u8 *arg0, s32 arg1) {
    f32 temp_f0;

    func_80137070(arg0 + 0x144);
    if ((func_800FEE3C(arg0 + 0x58, 0.01f, 0x3A03126F) != 0) && (M2C_FIELD(arg0, s16 *, 0x1C) == 2)) {
        func_808F0F38(arg0);
    }
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x58);
    M2C_FIELD(arg0, f32 *, 0x60) = temp_f0;
    M2C_FIELD(arg0, f32 *, 0x5C) = temp_f0;
    if ((M2C_FIELD(arg0, s16 *, 0x1C) == 1) && (func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, f32 *, 0xC) + 60.0f, 0x40A00000) != 0)) {
        func_808F0F38(arg0);
    }
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) + 0x1999);
    func_800B273C(arg1, arg0 + 8, 0x40400000, 0, 0xC, 5, 1, -1, 0xA, 0);
}
