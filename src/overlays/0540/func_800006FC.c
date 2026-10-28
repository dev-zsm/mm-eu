// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1D6C(s8);                          /* extern */
M2C_UNK func_801520F8(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B88460(u8 *, u8 *, M2C_UNK);     /* extern */
M2C_UNK func_80B885DC(u8 *, u8 *);              /* extern */
s32 func_80B899E4(u8 *, u8 *);                  /* extern */
extern M2C_UNK D_801E6EF0;

void func_800006FC(u8 *arg0, u8 *arg1) {
    u8 *temp_v0;

    func_80B885DC(arg0, arg1);
    if (M2C_FIELD(arg0, u8 *, 0x2B7) == 0) {
        if (func_80B899E4(arg0, arg1) != 0) {
            if ((M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x2B8), u8 *, 1) != 0) && ((M2C_FIELD(&D_801E6EF0, u8 *, 0xF2A) & 1) || (M2C_FIELD(&D_801E6EF0, u8 *, 0xF2B) & 0x80))) {
                M2C_FIELD(arg0, u8 *, 0x2B7) = 1U;
                return;
            }
            goto block_9;
        }
    } else {
        temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
        if ((M2C_FIELD(temp_v0, s32 *, 0xA6C) & 0x400) && (M2C_FIELD(temp_v0, s8 *, 0xAE7) != 0)) {
            func_801520F8(arg1, 0x30);
            func_801520F8(arg1, 9);
            func_801520F8(arg1, 0xA);
block_9:
            func_80B88460(arg0, arg1, 0);
            func_800F1D6C(M2C_FIELD(arg0, s8 *, 0x2B2));
            M2C_FIELD(arg1, u8 *, 0x1CA5) = (u8) (M2C_FIELD(arg1, u8 *, 0x1CA5) & 0xFFDF);
        }
    }
}
