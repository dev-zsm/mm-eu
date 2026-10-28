// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, u8 *);                  /* extern */
M2C_UNK func_800B8398(u8 *, u8 *, M2C_UNK);     /* extern */
M2C_UNK func_800F1944(s16);                         /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
M2C_UNK func_80151DF4(u8 *, s32, u8 *);         /* extern */
s16 func_809F1768(u8 *, u8 *);                  /* extern */
M2C_UNK func_809F1F88(u8 *, u8 *, M2C_UNK);     /* extern */

void func_80000C90(u8 *arg0, u8 *arg1) {
    u8 *sp24;
    f32 temp_f0;
    f32 temp_f0_2;
    s16 temp_v0;

    sp24 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    M2C_FIELD(arg0, s16 *, 0x1F0) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) - M2C_FIELD(arg0, s16 *, 0xBE));
    if (func_800B8254(arg0, arg1) != 0) {
        if (M2C_FIELD(arg0, s16 *, 0x39E) == 0) {
            if (func_800F1E2C() == 0x7C) {
                func_800F1D6C(0x7C);
            }
            M2C_FIELD(arg0, s16 *, 0x3A0) = (s16) M2C_FIELD(arg0, s16 *, 0x3A2);
            func_800F1944(M2C_FIELD(arg0, s16 *, 0x3A0));
            M2C_FIELD(arg0, s16 *, 0x39E) = 1;
        }
        M2C_FIELD(sp24, s32 *, 0xA70) = (s32) (M2C_FIELD(sp24, s32 *, 0xA70) | 0x20000000);
        temp_v0 = func_809F1768(arg0, arg1);
        M2C_FIELD(arg0, s16 *, 0x3B4) = temp_v0;
        func_80151DF4(arg1, temp_v0 & 0xFFFF, arg0);
        if ((M2C_FIELD(arg0, s16 *, 0x1C) & 0x1F) == 2) {
            M2C_FIELD(arg0, s16 *, 0x1F0) = -0x2000;
        }
        func_809F1F88(arg1, arg0, 0);
        return;
    }
    temp_f0 = M2C_FIELD(sp24, f32 *, 0x24);
    if ((M2C_FIELD(arg0, f32 *, 0x3BC) <= temp_f0) && (temp_f0 <= M2C_FIELD(arg0, f32 *, 0x3C0))) {
        temp_f0_2 = M2C_FIELD(sp24, f32 *, 0x2C);
        if ((M2C_FIELD(arg0, f32 *, 0x3C4) <= temp_f0_2) && (temp_f0_2 <= M2C_FIELD(arg0, f32 *, 0x3C8))) {
            func_800B8398(arg0, arg1, 0x43C80000);
        }
    }
    if (M2C_FIELD(arg0, u8 *, 0x3BA) == 1) {
        M2C_FIELD(arg0, u8 *, 0x3BA) = 0U;
        func_809F1F88(arg1, arg0, 0);
    }
}
