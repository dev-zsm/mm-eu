#include "types.h"

extern f32 D_801D79EC;
s32 Math3D_TriChkPointParaYImpl(f32 a0, f32 a1, f32 a2, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7);
float fabsf(float);
#pragma intrinsic (fabsf)

s32 Math3D_TriChkPointParaYIntersectDist(f32 a0, f32 a1, f32 a2, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7, f32 a8,
                                         f32 *out, f32 a10) {
    if (fabsf(a4) < D_801D79EC) {
        return 0;
    }
    if (Math3D_TriChkPointParaYImpl(a0, a1, a2, a7, a8, 300.0f, a10, a4)) {
        *out = ((-a3 * a8) - (a5 * a7) - a6) / a4;
        return 1;
    }
    return 0;
}
