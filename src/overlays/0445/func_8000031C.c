// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFAD8(u8 *, f32, M2C_UNK, M2C_UNK, f32); /* extern */
u16 func_80ADBD8C(u8 *, u16);                     /* extern */
extern M2C_UNK D_80ADBF2C;
extern f32 D_80ADC280;
extern f32 D_80ADC284;

void func_8000031C(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v1;
    u16 temp_v0;

    temp_v0 = func_80ADBD8C(arg0, M2C_FIELD(arg0, u16 *, 0x1CC));
    temp_v1 = temp_v0 & 0xFFFF;
    M2C_FIELD(arg0, u16 *, 0x1CC) = temp_v0;
    if (temp_v1 & 0xC) {
        if (temp_v1 & 4) {
            M2C_FIELD(arg0, u16 *, 0x1CC) = (u16) (temp_v1 | 2);
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80ADBF2C;
        return;
    }
    if (temp_v1 & 0x10) {
        if (!(M2C_FIELD(arg0, u16 *, 0x1CE) & 0x10)) {
            func_800B8C4C(arg0, 0x2979);
        }
        func_800FFAD8(arg0 + 0x28, M2C_FIELD(arg0, f32 *, 0xC) - 8.0f, 0x3F800000, 0x40000000, D_80ADC280);
        return;
    }
    if (M2C_FIELD(arg0, u16 *, 0x1CE) & 0x10) {
        func_800B8C4C(arg0, 0x297A);
    }
    func_800FFAD8(arg0 + 0x28, M2C_FIELD(arg0, f32 *, 0xC), 0x3F800000, 0x40000000, D_80ADC284);
}
