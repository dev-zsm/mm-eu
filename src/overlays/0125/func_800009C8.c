// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern f32 D_808EFBAC;
extern f32 D_808EFBB0;

void func_800009C8(u8 *arg0, u8 *arg1, u8 *arg2) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 var_f12;

    temp_f0 = M2C_FIELD(arg2, f32 *, 0);
    temp_f2 = M2C_FIELD(arg1, f32 *, 0);
    if (temp_f0 < temp_f2) {
        var_f12 = D_808EFBAC;
        M2C_FIELD(arg0, f32 *, 0x620) = (f32) (temp_f2 * var_f12);
    } else {
        var_f12 = D_808EFBB0;
        M2C_FIELD(arg0, f32 *, 0x620) = (f32) (-temp_f0 * var_f12);
    }
    temp_f0_2 = M2C_FIELD(arg2, f32 *, 8);
    temp_f2_2 = M2C_FIELD(arg1, f32 *, 8);
    if (temp_f0_2 < temp_f2_2) {
        M2C_FIELD(arg0, f32 *, 0x624) = (f32) (temp_f2_2 * var_f12);
        return;
    }
    M2C_FIELD(arg0, f32 *, 0x624) = (f32) (-temp_f0_2 * var_f12);
}
