#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFC68(u8 *, f32, f32, u8 *); /* extern */
M2C_UNK func_80998BDC(u8 *, s32);                 /* extern */
extern u8 *D_809A3D10;

void func_80002DE8(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x14C);
    if ((temp_v0 > 0) && (temp_v0 < 0x17)) {
        if (temp_v0 == 1) {
            D_809A3D10 = NULL;
        } else {
            D_809A3D10 = arg0;
        }
    }
    func_800FFC68(arg0 + 0x70, 1.0f, 1.0f, arg0);
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x14A);
    if (temp_v0_2 < 0x14) {
        if (temp_v0_2 & 1) {
            M2C_FIELD(arg0, s16 *, 0x184) = 0x708;
        } else {
            M2C_FIELD(arg0, s16 *, 0x184) = -0x708;
        }
    } else {
        M2C_FIELD(arg0, s16 *, 0x186) = 0;
    }
    if (M2C_FIELD(arg0, s16 *, 0x14A) == 0) {
        func_80998BDC(arg0, arg1);
    }
}
