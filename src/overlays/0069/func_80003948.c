#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0069.h"

f32 func_800FEB44(s16);                             /* extern */
s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_8013F090(f32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_801A0070(u8 *, M2C_UNK);             /* extern */
s32 func_8087C000(u8 *, s32);                     /* extern */
M2C_UNK func_8087D50C(u8 *);                      /* extern */
M2C_UNK func_8087DCF8(u8 *);                      /* extern */
M2C_UNK func_8087ECB0(u8 *);                      /* extern */
M2C_UNK func_8087ECD4(u8 *);                      /* extern */
M2C_UNK func_808851A0(u8 *, M2C_UNK *, s16 *);    /* extern */

void func_80003948(u8 *arg0, s32 arg1) {
    M2C_UNK sp2C;
    s16 sp2A;
    s32 temp_v0;
    s32 temp_v0_2;

    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if (M2C_FIELD(arg0, f32 *, 0x210) > 25.0f) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x1E8);
        if (!(temp_v0 & 0x800)) {
            M2C_FIELD(arg0, s32 *, 0x1E8) = (s32) (temp_v0 | 0x800);
            if (M2C_FIELD(arg0, s32 *, 0x150) == 2) {
                func_801A0070(arg0 + 0xEC, 0x282B);
            } else {
                func_801A0070(arg0 + 0xEC, 0x282B);
            }
            func_8013F090(0, 0xB4, 0x14, 0x64);
        }
    }
    func_808851A0(arg0 + 0x264, &sp2C, &sp2A);
    if (func_80137070(arg0 + 0x1A4) != 0) {
        if (func_8087C000(arg0, arg1) == 1) {
            temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x1E8);
            if (temp_v0_2 & 0x10) {
                M2C_FIELD(arg0, s32 *, 0x148) = 0x64;
                M2C_FIELD(arg0, s32 *, 0x14C) = 0x64;
                M2C_FIELD(arg0, s32 *, 0x1E8) = (s32) (temp_v0_2 & ~0x10);
                func_8087ECD4(arg0);
                return;
            }
            if (temp_v0_2 & 0x20) {
                M2C_FIELD(arg0, s32 *, 0x148) = 0x64;
                M2C_FIELD(arg0, s32 *, 0x14C) = 0x64;
                M2C_FIELD(arg0, s32 *, 0x1E8) = (s32) (temp_v0_2 & ~0x20);
                func_8087DCF8(arg0);
                return;
            }
            if (func_800FEB44(sp2A) <= -0.5f) {
                func_8087ECB0(arg0);
                return;
            }
            func_8087D50C(arg0);
            return;
        }
        func_8087D50C(arg0);
    }
}
