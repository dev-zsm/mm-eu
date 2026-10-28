// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK func_800F0308(s32, u8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80C05014(u8 *);                      /* extern */
M2C_UNK func_80C05224(u8 *);                      /* extern */
M2C_UNK func_80C06208(u8 *, s32);                 /* extern */
extern M2C_UNK D_80C06AA4;

void func_800008A0(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3E2);
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, s16 *, 0x3E2) = 0;
        M2C_FIELD(arg0, f32 *, 0x2D8) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x2D4) = 0.0f;
        if (M2C_FIELD(arg0, u8 *, 0xB7) != 0) {
            func_800BC8F4(arg0, 0x4000, 0xFF, 0, 8);
            func_800BD9E0(arg0 + 0x1E4, &D_80C06AA4, 3);
            func_800B8C4C(arg0, 0x3832);
            M2C_FIELD(arg0, u8 *, 0x3E8) = (u8) (M2C_FIELD(arg0, u8 *, 0x3E8) | 1);
            func_80C05014(arg0);
            return;
        }
        func_800F0308(arg1, arg0 + 0x24, 0x28, 0x3833);
        func_80C05224(arg0);
        return;
    }
    if (temp_v0 == 1) {
        func_80C06208(arg0, arg1);
    }
}
