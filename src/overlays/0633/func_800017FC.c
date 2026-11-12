#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_800A7C50(s32, u8 *, M2C_UNK);        /* extern */
s16 func_800B6B2C(u8 *, M2C_UNK *);               /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK func_80BF5724(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_6000278;
extern M2C_UNK D_80BF6EFC;
extern f32 D_80BF8468;
extern f32 D_80BF846C;
extern f32 D_80BF8470;
extern M2C_UNK D_80BF86C0;

void func_800017FC(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    func_80137934(arg0 + 0x144, &D_6000278, 0xC0800000);
    func_80BF5724(arg0, 0xF);
    if (M2C_FIELD(arg0, u8 *, 0xB9) != 3) {
        M2C_FIELD(arg0, f32 *, 0x70) = 4.0f;
    } else {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    }
    temp_v0 = M2C_FIELD(arg0, u8 *, 0xB9);
    if (temp_v0 == 5) {
        func_800BC8F4(arg0, 0, 0xFF, 0, 0x28);
        func_800B8C4C(arg0, 0x389E);
    } else if (temp_v0 == 1) {
        func_800BC8F4(arg0, 0, 0xFF, 0, 0x28);
        func_800B8C4C(arg0, 0x389E);
    } else {
        func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x28);
        func_800B8C4C(arg0, 0x3A98);
    }
    M2C_FIELD(arg0, u8 *, 0x281) = (u8) (M2C_FIELD(arg0, u8 *, 0x281) & 0xFFFE);
    if (M2C_FIELD(arg0, s32 *, 0x3E8) == 0) {
        M2C_FIELD(arg0, s16 *, 0x190) = -0x1000;
        M2C_FIELD(arg0, s16 *, 0x192) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
    } else {
        M2C_FIELD(arg0, s16 *, 0x190) = func_800B6B2C(arg0, &D_80BF86C0);
    }
    M2C_FIELD(arg0, s16 *, 0x18E) = 0x28;
    if (func_8008704C() < D_80BF8468) {
        func_800A7C50(arg1, arg0 + 0x3C, 0);
    }
    if (func_8008704C() < D_80BF846C) {
        func_800A7C50(arg1, arg0 + 0x3C, 0);
    }
    if (func_8008704C() < D_80BF8470) {
        func_800A7C50(arg1, arg0 + 0x3C, 0);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80BF6EFC;
}
