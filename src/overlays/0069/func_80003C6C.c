#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
s32 func_800EDF78(s32);                             /* extern */
s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_8013F090(f32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_801A0070(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8087D50C(u8 *);                      /* extern */
M2C_UNK func_8087ECD4(u8 *);                      /* extern */
extern s32 D_801E6EF0;
extern f32 D_808889D4;

void func_80003C6C(u8 *arg0, s32 arg1) {
    f32 temp_f0;

    temp_f0 = M2C_FIELD(arg0, f32 *, 0x70);
    if (temp_f0 > 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x70) = (f32) (temp_f0 - D_808889D4);
        if (M2C_FIELD(arg0, f32 *, 0x70) < 0.0f) {
            M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        }
    }
    if ((M2C_FIELD(arg0, s32 *, 0x1E8) & 0x400) && (M2C_FIELD(arg0, f32 *, 0x1BC) > 29.0f)) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        if ((func_8008704C() > 0.5f) && ((D_801E6EF0 != 0x6400) || (func_800EDF78(arg1) == 0))) {
            if (M2C_FIELD(arg0, s32 *, 0x1E8) & 0x08000000) {
                if (M2C_FIELD(arg0, s32 *, 0x150) == 2) {
                    func_801A0070(arg0 + 0x218, 0x2844);
                } else {
                    func_801A0070(arg0 + 0x218, 0x2805);
                }
            }
            func_8013F090(0, 0xB4, 0x14, 0x64);
            M2C_FIELD(arg0, s32 *, 0x1E8) = (s32) (M2C_FIELD(arg0, s32 *, 0x1E8) & ~0x400);
        } else {
            func_8087D50C(arg0);
        }
    }
    if (M2C_FIELD(arg0, f32 *, 0x1BC) > 29.0f) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    } else if ((M2C_FIELD(arg0, f32 *, 0x70) > 3.0f) && (M2C_FIELD(arg0, s32 *, 0x1E8) & 0x10)) {
        M2C_FIELD(arg0, f32 *, 0x70) = 3.0f;
    }
    if (func_80137070(arg0 + 0x1A4) != 0) {
        if (M2C_FIELD(arg0, s32 *, 0x1E8) & 0x10) {
            M2C_FIELD(arg0, s32 *, 0x148) = 0x64;
            M2C_FIELD(arg0, s32 *, 0x14C) = 0x64;
            func_8087ECD4(arg0);
            M2C_FIELD(arg0, s32 *, 0x1E8) = (s32) (M2C_FIELD(arg0, s32 *, 0x1E8) & ~0x10);
            return;
        }
        func_8087D50C(arg0);
    }
}
