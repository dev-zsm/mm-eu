#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BA9E4(s32, s32, M2C_UNK, f32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_800BB80C(s32, u8 *);                 /* extern */
s32 func_800BDFB0(u8 *);                          /* extern */
M2C_UNK func_80B11D28(u8 *);                      /* extern */
M2C_UNK func_80B12654(u8 *);                      /* extern */
extern f32 D_80B144C0;

void func_80001D48(u8 *arg0, s32 arg1) {
    u8 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x33D);
    if (temp_v0 & 2) {
        M2C_FIELD(arg0, u8 *, 0x33D) = (u8) (temp_v0 & 0xFFFD);
        if (func_800BDFB0(arg0) == 0) {
            func_800BB80C(arg1, arg0);
            func_800B8C4C(arg0, 0x3876);
        } else if (M2C_FIELD(arg0, u8 *, 0xB8) != 0) {
            func_800B8C4C(arg0, 0x3875);
        }
        temp_v0_2 = M2C_FIELD(arg0, u8 *, 0xB9);
        if (temp_v0_2 != 0xE) {
            if (temp_v0_2 == 0xF) {
                func_80B12654(arg0);
                return;
            }
            if (temp_v0_2 == 4) {
                M2C_FIELD(arg0, f32 *, 0x298) = 4.0f;
                M2C_FIELD(arg0, f32 *, 0x29C) = (f32) D_80B144C0;
                func_800BA9E4(arg1 + 0x1CA0, arg1, 0xA2, (f32) M2C_FIELD(arg0, s16 *, 0x352), (f32) M2C_FIELD(arg0, s16 *, 0x354), (f32) M2C_FIELD(arg0, s16 *, 0x356), 0, 0, 0, 4);
            }
            func_80B11D28(arg0);
        }
    }
}
