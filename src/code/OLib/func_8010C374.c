// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_olib.h"

VecSph OLib_Vec3fToVecSph(Vec3f* vec) {
    VecSph sph;
    f32 distXZSq = SQ(vec->x) + SQ(vec->z);
    f32 distXZ = sqrtf(distXZSq);

    if ((distXZ == 0.0f) && (vec->y == 0.0f)) {
        sph.pitch = 0;
    } else {
        sph.pitch = CAM_DEG_TO_BINANG(RAD_TO_DEG(Math_FAtan2F(distXZ, vec->y)));
    }

    sph.r = sqrtf(SQ(vec->y) + distXZSq);
    if ((vec->x == 0.0f) && (vec->z == 0.0f)) {
        sph.yaw = 0;
    } else {
        sph.yaw = CAM_DEG_TO_BINANG(RAD_TO_DEG(Math_FAtan2F(vec->x, vec->z)));
    }

    return sph;
}
