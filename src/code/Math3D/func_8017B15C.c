#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;

extern f32 D_801D79D4;
f32 Math3D_Vec3fMagnitude(Vec3f *);
f32 fabsf(f32);
#pragma intrinsic (fabsf)

s32 Math3D_CosOut(Vec3f *a, Vec3f *b, f32 *dst) {
    f32 prod;
    f32 la;

    la = Math3D_Vec3fMagnitude(a);
    prod = Math3D_Vec3fMagnitude(b) * la;
    if (fabsf(prod) < D_801D79D4) {
        *dst = 0.0f;
        return 1;
    }
    *dst = (a->x * b->x + a->y * b->y + a->z * b->z) / prod;
    return 0;
}
