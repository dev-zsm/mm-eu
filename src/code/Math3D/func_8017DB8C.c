#include "types.h"

float fabsf(float);
#pragma intrinsic (fabsf)

extern f32 D_801D7A10;
extern s32 Math3D_TriChkPointParaXImpl(void *a0, void *a1, void *a2, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7);

s32 Math3D_TriChkLineSegParaXDist(void *a0, void *a1, void *a2, f32 *a3, f32 a4, f32 a5, f32 a6) {
    if (fabsf(*a3) < D_801D7A10) {
        return 0;
    }
    if (Math3D_TriChkPointParaXImpl(a0, a1, a2, a4, a5, 0.0f, a6, *a3)) {
        return 1;
    }
    return 0;
}
