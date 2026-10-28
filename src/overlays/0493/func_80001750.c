// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, f32);                 /* extern */
M2C_UNK func_800FFAD8(s32, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80B416D8(u8 *, s32);                 /* extern */
extern f32 D_80B43180;
extern f32 D_80B43184;

void func_80001750(u8 *arg0, s32 arg1) {
    u8 *temp_v0;

    func_800FFAD8(arg0 + 0x58, 0x3C54FDF3, 0x3F333333, 0x38D1B717, D_80B43180);
    func_800B6564(arg0, M2C_FIELD(arg0, f32 *, 0x58));
    if (D_80B43184 == M2C_FIELD(arg0, f32 *, 0x58)) {
        temp_v0 = M2C_FIELD(arg0, u8 **, 0x360);
        M2C_FIELD(temp_v0, u16 *, 0x32C) = (u16) (M2C_FIELD(temp_v0, u16 *, 0x32C) | 0x1000);
        M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x360), u8 **, 0x360) = arg0;
        func_80B416D8(arg0, arg1);
    }
}
