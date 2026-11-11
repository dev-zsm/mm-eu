#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800A8248(s32, u8 *, u8 *, M2C_UNK); /* extern */
s32 func_800FEE3C(u8 *, f32, f32);            /* extern */
M2C_UNK func_8098062C(u8 *);                      /* extern */
extern s32 D_80980E0C;
extern f32 D_80980E30;
extern f32 D_80980E34;

void func_80000B94(u8 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 var_f0;

    if (M2C_FIELD(arg0, s16 *, 0x1C) != 0) {
        var_f0 = D_80980E30;
    } else {
        var_f0 = D_80980E34;
    }
    if (func_800FEE3C(arg0 + 0x58, 0, var_f0) != 0) {
        if (M2C_FIELD(arg0, s16 *, 0x1C) == 0) {
            D_80980E0C += 1;
            func_800A8248(arg1, arg0, arg0 + 0x24, 0x80);
        } else {
            func_800A8248(arg1, arg0, arg0 + 0x24, 0x90);
        }
        func_8098062C(arg0);
    }
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x58);
    M2C_FIELD(arg0, f32 *, 0x5C) = temp_f0;
    M2C_FIELD(arg0, f32 *, 0x60) = temp_f0;
}
