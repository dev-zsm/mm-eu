// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF30C(u8 *, M2C_UNK *);           /* extern */
f32 func_8017B984();                                /* extern */
extern M2C_UNK D_801C9EE0;
extern f32 D_80A50790;

s32 func_800004BC(u8 *arg0, u8 *arg1) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = func_8017B984();
    if (temp_f0 < D_80A50790) {
        func_800FF30C(arg0, &D_801C9EE0);
        return 0;
    }
    temp_f2 = 1.0f / temp_f0;
    M2C_FIELD(arg1, f32 *, 0) = (f32) (M2C_FIELD(arg0, f32 *, 0) * temp_f2);
    M2C_FIELD(arg1, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 4) * temp_f2);
    M2C_FIELD(arg1, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) * temp_f2);
    return 1;
}
