// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_800B6564(u8 *, f32);                 /* extern */
extern f32 D_809279B0;
extern f32 D_809279B4;
extern f32 D_809279B8;
extern f32 D_809279BC;

void func_80000000(u8 *arg0) {
    f32 var_f2;
    s32 temp_v0;

    temp_v0 = ((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 0xC) & 3;
    if (temp_v0 == 0) {
        var_f2 = D_809279B0;
    } else if (temp_v0 == 1) {
        var_f2 = D_809279B4;
    } else {
        var_f2 = (func_8008704C() * D_809279B8) + D_809279BC;
    }
    func_800B6564(arg0, var_f2);
}
