// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern f32 D_801D7A04;
float fabsf(float);
#pragma intrinsic (fabsf)
s32 Math3D_TriChkPointParaXImpl(s32 a0, s32 a1, s32 a2, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7);

s32 Math3D_TriChkPointParaXIntersect(s32 a0, s32 a1, s32 a2, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7, f32 a8, f32 *a9) {
    if (fabsf(a3) < D_801D7A04) {
        return 0;
    }
    if (Math3D_TriChkPointParaXImpl(a0, a1, a2, a7, a8, 300.0f, 1.0f, a3) != 0) {
        *a9 = (((-a4 * a7) - (a5 * a8)) - a6) / a3;
        return 1;
    }
    return 0;
}
