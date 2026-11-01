#include "types.h"

f32 Math3D_Vec3fMagnitude(f32 *v);
extern f32 D_801D79D4;
f32 fabsf(f32);
#pragma intrinsic (fabsf)

s32 Math3D_CosOut(f32 *a, f32 *b, f32 *out) {
    f32 lb;
    f32 la;

    la = Math3D_Vec3fMagnitude(a);
    lb = Math3D_Vec3fMagnitude(b) * la;
    if (fabsf(lb) < D_801D79D4) {
        *out = 0.0f;
        return 1;
    }
    *out = (a[0] * b[0] + a[1] * b[1] + b[2] * a[2]) / lb;
    return 0;
}
