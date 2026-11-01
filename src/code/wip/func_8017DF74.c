#include "types.h"

extern f32 D_801D7A14;
extern s32 Math3D_TriChkPointParaZImpl(f32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g, f32 h);
f32 fabsf(f32);
#pragma intrinsic (fabsf)

s32 Math3D_TriChkPointParaZIntersect(s32 a0, s32 a1, s32 a2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 *arg9) {
    if (fabsf(arg5) < D_801D7A14) {
        return 0;
    }
    if (Math3D_TriChkPointParaZImpl(arg5, a1, a2, arg7, arg8, 300.0f, 1.0f, arg5)) {
        *arg9 = (-arg3 * arg7 - arg4 * arg8 - arg6) / arg5;
        return 1;
    }
    return 0;
}
