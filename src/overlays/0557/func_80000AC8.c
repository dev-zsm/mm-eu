// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800F1D6C(s8);                          /* extern */
s32 func_80BA88A0(u8 *);                          /* extern */
s32 func_80BA8AA8(u8 *, s32, M2C_UNK);            /* extern */
extern M2C_UNK D_80BA9120;
extern M2C_UNK D_80BA916C;

void func_80000AC8(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    if (func_80BA88A0(arg0) != 0) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x160);
        M2C_FIELD(arg0, f32 *, 0x70) = 40.0f;
        if (temp_v0 > 0) {
            M2C_FIELD(arg0, s32 *, 0x164) = (s32) (temp_v0 - 1);
        } else {
            M2C_FIELD(arg0, M2C_UNK **, 0x16C) = &D_80BA9120;
            func_800F1D6C(M2C_FIELD(arg0, s8 *, 0x38));
            func_800B8C4C(arg0, 0x29A3);
        }
    }
    if (func_80BA8AA8(arg0, arg1, 0) != 0) {
        func_800F1D6C(M2C_FIELD(arg0, s8 *, 0x38));
        M2C_FIELD(arg0, M2C_UNK **, 0x16C) = &D_80BA916C;
        func_800B8C4C(arg0, 0x29A4);
    }
}
