// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BA9E4(s32, s32, M2C_UNK, f32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_800BB80C(s32, u8 *);                 /* extern */
s32 func_800BDFB0(u8 *);                          /* extern */
M2C_UNK func_801A3D9C();                            /* extern */
M2C_UNK func_80B47714(u8 *);                      /* extern */

s32 func_800027A8(u8 *arg0, s32 arg1) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x2BD);
    if ((temp_v0 & 2) && !(temp_v0 & 4)) {
        M2C_FIELD(arg0, u8 *, 0x2BD) = (u8) (temp_v0 & 0xFFFD);
        if (M2C_FIELD(arg0, u8 *, 0xB9) == 0xF) {
            return 1;
        }
        if (func_800BDFB0(arg0) == 0) {
            M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
            func_800B8C4C(arg0, 0x3876);
            func_800BB80C(arg1, arg0);
            if (M2C_FIELD(arg0, s16 *, 0x1C) == 1) {
                func_801A3D9C();
            }
        } else {
            func_800B8C4C(arg0, 0x3875);
        }
        if (M2C_FIELD(arg0, u8 *, 0xB9) == 4) {
            M2C_FIELD(arg0, f32 *, 0x21C) = 4.0f;
            M2C_FIELD(arg0, f32 *, 0x220) = 1.0f;
            func_800BA9E4(arg1 + 0x1CA0, arg1, 0xA2, (f32) M2C_FIELD(arg0, s16 *, 0x2D2), (f32) M2C_FIELD(arg0, s16 *, 0x2D4), (f32) M2C_FIELD(arg0, s16 *, 0x2D6), 0, 0, 0, 4);
        }
        func_80B47714(arg0);
        return 1;
    }
    return 0;
}
