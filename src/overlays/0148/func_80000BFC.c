// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEE3C(u8 *, f32, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_80913C90(u8 *);                      /* extern */
M2C_UNK func_80913E3C(u8 *);                      /* extern */
extern f32 D_80915010;
extern f32 D_80915014;

void func_80000BFC(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f0;
    f32 var_f0;
    s32 temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0x1C) == 1) {
        var_f0 = D_80915010;
    } else {
        var_f0 = D_80915014;
    }
    temp_v0 = func_800FEE3C(arg0 + 0x58, var_f0, 0x3A1D4952, arg0);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x58);
    M2C_FIELD(arg0, f32 *, 0x5C) = temp_f0;
    M2C_FIELD(arg0, f32 *, 0x60) = temp_f0;
    if (temp_v0 != 0) {
        if (M2C_FIELD(arg0, s16 *, 0x1C) == 1) {
            func_80913E3C(arg0);
            return;
        }
        func_80913C90(arg0);
    }
}
