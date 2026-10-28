// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern f32 D_801D79F0;
f32 fabsf(f32);
#pragma intrinsic (fabsf)
s32 Math3D_TriChkPointParaYImpl(s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g, f32 h);
s32 Math3D_TriChkPointParaYIntersectInsideTri(s32 p0, s32 p1, s32 p2, f32 p3, f32 p4, f32 p5, f32 p6, f32 p7, f32 p8, f32 *out, f32 p10) {
    if (fabsf(p4) < D_801D79F0) {
        return 0;
    }
    if (Math3D_TriChkPointParaYImpl(p0, p1, p2, p7, p8, 0.0f, p10, p4) != 0) {
        *out = (((-p3 * p8) - (p5 * p7)) - p6) / p4;
        return 1;
    }
    return 0;
}
