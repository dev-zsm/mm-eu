#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
M2C_UNK func_80994798(u8 *, s32);                 /* extern */
extern f32 D_80995E90;
extern f32 D_80995E94;

void func_800020BC(u8 *arg0, s32 arg1) {
    f32 temp_f0;
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2AA);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x15C);
    if ((temp_v0 == 0xB) || (temp_v0 == 0xA)) {
        if (M2C_FIELD(arg0, s16 *, 0x2A8) != 0) {
            func_800BF550(arg1, arg0, arg0 + 0x2B4, 0xC, 2, D_80995E90, D_80995E94);
            M2C_FIELD(arg0, s16 *, 0x2A8) = 0;
            M2C_FIELD(arg0, s16 *, 0x2AA) = 0;
            goto block_4;
        }
    } else {
block_4:
        if ((M2C_FIELD(arg0, f32 *, 0x350) <= temp_f0) && (M2C_FIELD(arg0, s16 *, 0x288) == 0)) {
            func_80994798(arg0, arg1);
        }
    }
}
