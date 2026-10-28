// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(u8 *, s32);                     /* extern */
s8 func_800F1EA8(s8);                               /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
s32 func_80B87448(u8 *);                          /* extern */
s32 func_80B874A8(u8 *, u8 *);                  /* extern */
M2C_UNK func_80B87530(u8 *);                      /* extern */
extern s32 D_80B88450;

void func_800003A4(u8 *arg0, u8 *arg1) {
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg1, u8 *, 0x1CA5);
    if (!(temp_v1 & 0x20)) {
        if (M2C_FIELD(arg0, s16 *, 0x1C) & 0x200) {
            if (func_80B874A8(arg0, arg1) == 0) {
                return;
            }
            goto block_7;
        }
        if (D_80B88450 != 0) {
            M2C_FIELD(arg1, u8 *, 0x1CA5) = (u8) (temp_v1 | 0x80);
        }
        if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F) != 0) {
block_7:
            if ((D_80B88450 == 0) || (func_80B87448(arg0) != 0)) {
                func_80B87530(arg0);
                if (D_80B88450 == 0) {
                    M2C_FIELD(arg0, s8 *, 0x15E) = 0x19;
                    func_8019FF78(0x485F);
                } else {
                    M2C_FIELD(arg0, s8 *, 0x15E) = func_800F1EA8(M2C_FIELD(arg0, s8 *, 0x15F));
                    if (M2C_FIELD(arg0, s8 *, 0x15E) < 0) {
                        M2C_FIELD(arg0, s8 *, 0x15E) = 0x32;
                    }
                    M2C_FIELD(arg1, u8 *, 0x1CA5) = (u8) (M2C_FIELD(arg1, u8 *, 0x1CA5) | 0x10);
                }
            }
            M2C_FIELD(M2C_FIELD(arg1, u8 **, 0x1CCC), f32 *, 0xAD0) = 0.0f;
        }
    }
}
