// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B2E50(u8 *, u8 *, s32);         /* extern */
M2C_UNK func_800B8BDC(u8 *, M2C_UNK);             /* extern */
s32 func_80136480(u8 *, u8 *);                  /* extern */
s32 func_8082D538(u8 *, M2C_UNK, M2C_UNK);        /* extern */
M2C_UNK func_80833064(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808337B4(u8 *, u8 *);              /* extern */
M2C_UNK func_80836038(u8 *, u8 *);              /* extern */
M2C_UNK func_8085AAD4(u8 *, M2C_UNK);             /* extern */

void func_80026C84(u8 *arg0, u8 *arg1) {
    s8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s8 *, 0xAE7);
    if (temp_v0 >= 0) {
        if (temp_v0 < 6) {
            M2C_FIELD(arg0, s8 *, 0xAE7) = (s8) (temp_v0 + 1);
        } else {
            M2C_FIELD(arg0, f32 *, 0xB48) = (f32) ((f32) (temp_v0 >> 1) * 22.0f);
            if (func_8082D538(arg0, 1, 0x64) != 0) {
                M2C_FIELD(arg0, s8 *, 0xAE7) = -1;
                func_800B2E50(arg1, arg0 + 0x24, M2C_FIELD(arg0, s32 *, 0x58));
                func_800B8BDC(arg0, 0x875);
            }
            if (M2C_FIELD(arg0, u8 *, 0x14B) == 2) {
                func_808337B4(arg1, arg0);
                M2C_FIELD(arg0, s32 *, 0x248) = 0;
                M2C_FIELD(arg0, s16 *, 0xAE8) = -0x28;
                M2C_FIELD(arg0, s8 *, 0xAE7) = 1;
                M2C_FIELD(arg0, f32 *, 0xAD0) = 0.0f;
            } else if (!(M2C_FIELD(arg1, s32 *, 0x18840) & 3)) {
                func_8085AAD4(arg1, -1);
            }
        }
        M2C_FIELD(arg0, s32 *, 0xA70) = (s32) (M2C_FIELD(arg0, s32 *, 0xA70) | 0x4000);
        return;
    }
    if (func_80136480(arg1, arg0 + 0x240) != 0) {
        func_80836038(arg0, arg1);
        func_80833064(arg0, 0x14);
    }
}
