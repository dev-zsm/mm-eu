#include "types.h"

extern f32 D_801D7A00;
extern s32 Math3D_TriChkPointParaYImplNoCheckRange(s32, s32, s32, f32, f32, f32, f32, f32);
f32 fabsf(f32);
#pragma intrinsic (fabsf)

s32 Math3D_TriChkPointParaYNoRangeCheckIntersectInsideTri(s32 a0, s32 a1, s32 a2, f32 nx, f32 ny, f32 nz, f32 dist, f32 z, f32 x, f32 *yIntersect, f32 chkDist) {
    if (fabsf(ny) < D_801D7A00) {
        return 0;
    }
    if (Math3D_TriChkPointParaYImplNoCheckRange(a0, a1, a2, z, x, 0.0f, chkDist, ny) != 0) {
        *yIntersect = (((-nx * x) - (nz * z)) - dist) / ny;
        return 1;
    }
    return 0;
}
