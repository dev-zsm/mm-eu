// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0368.h"

f32 func_8017B984();                                /* extern */
extern f32 D_80A69280;

s32 ObjMine_GetUnitVec3f(Vec3f *src, Vec3f *dst) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = func_8017B984();
    if (temp_f0 < D_80A69280) {
        return 0;
    }
    temp_f2 = 1.0f / temp_f0;
    M2C_FIELD(dst, f32 *, 0) = (f32) (M2C_FIELD(src, f32 *, 0) * temp_f2);
    M2C_FIELD(dst, f32 *, 4) = (f32) (M2C_FIELD(src, f32 *, 4) * temp_f2);
    M2C_FIELD(dst, f32 *, 8) = (f32) (M2C_FIELD(src, f32 *, 8) * temp_f2);
    return 1;
}
