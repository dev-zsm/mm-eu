#include "types.h"
#include "m2c_compat.h"

f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK func_801A0070(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_6015CD0;
extern M2C_UNK D_80AEE210;

void func_80004130(u8 *arg0) {
    f32 sp24;
    f32 temp_f6;

    func_80137828(arg0 + 0x144, &D_6015CD0, 0xC0400000);
    M2C_FIELD(arg0, u8 *, 0x494) = (u8) (M2C_FIELD(arg0, u8 *, 0x494) & 0xFFFE);
    M2C_FIELD(arg0, u8 *, 0x495) = (u8) (M2C_FIELD(arg0, u8 *, 0x495) & 0xFFFB);
    M2C_FIELD(arg0, s16 *, 0x1A6) = 0;
    M2C_FIELD(arg0, s8 *, 0x195) = 0;
    M2C_FIELD(arg0, f32 *, 0x1C8) = 0.0f;
    if (M2C_FIELD(arg0, u8 *, 0x192) == 1) {
        func_800FF30C(arg0 + 0x3734, arg0 + 0x380);
        M2C_FIELD(arg0, f32 *, 0x1B8) = (f32) (M2C_FIELD(arg0, f32 *, 0x70) + 100.0f);
        sp24 = func_800FEB44(0xA00);
        M2C_FIELD(arg0, f32 *, 0x37AC) = (f32) (func_800FEB84(M2C_FIELD(arg0, s16 *, 0xBE)) * sp24);
        M2C_FIELD(arg0, f32 *, 0x37B0) = func_800FEB84(0xA00);
        sp24 = func_800FEB44(0xA00);
        temp_f6 = func_800FEB44(M2C_FIELD(arg0, s16 *, 0xBE)) * sp24;
        M2C_FIELD(arg0, f32 *, 0x37B4) = temp_f6;
        M2C_FIELD(arg0, u8 *, 0x192) = 2U;
        M2C_FIELD(arg0, f32 *, 0x1C8) = 0.0f;
        func_801A0070(arg0 + 0x458, 0x3852);
        M2C_FIELD(arg0, u8 *, 0x37C8) = (u8) (M2C_FIELD(arg0, u8 *, 0x37C8) | 1);
    }
    M2C_FIELD(arg0, s16 *, 0x19C) = 0x3C;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AEE210;
    M2C_FIELD(arg0, f32 *, 0x70) = 20.0f;
}
