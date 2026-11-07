// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass.h"

s32 ref_func_809A9110(PlayState* play, Vec3f* pos) {
    f32 w;
    Vec3f projectedPos;

    SkinMatrix_Vec3fMtxFMultXYZW(&play->viewProjectionMtxF, pos, &projectedPos, &w);

    if ((play->projectionMtxFDiagonal.z * -130.13191f) < projectedPos.z) {
        if (w < 1.0f) {
            w = 1.0f;
        }

        if (((fabsf(projectedPos.x) - (130.13191f * play->projectionMtxFDiagonal.x)) < w) &&
            ((fabsf(projectedPos.y) - (130.13191f * play->projectionMtxFDiagonal.y)) < w)) {
            return true;
        }
    }
    return false;
}
