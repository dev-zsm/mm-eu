// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, f32);                 /* extern */
M2C_UNK func_800FFAD8(s32, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80B41B9C(u8 *, s32);                 /* extern */
extern f32 D_80B43188;
extern f32 D_80B4318C;

void func_8000182C(u8 *arg0, s32 arg1) {
    func_800FFAD8(arg0 + 0x58, 0x3C54FDF3, 0x3F333333, 0x38D1B717, D_80B43188);
    func_800B6564(arg0, M2C_FIELD(arg0, f32 *, 0x58));
    if (D_80B4318C == M2C_FIELD(arg0, f32 *, 0x58)) {
        M2C_FIELD(arg0, u16 *, 0x32C) = (u16) (M2C_FIELD(arg0, u16 *, 0x32C) | 0x800);
        func_80B41B9C(arg0, arg1);
    }
}
