// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;

extern f32 D_801D79C0;
f32 Math3D_Vec3fMagnitude(Vec3f *v);
f32 fabsf(f32);
#pragma intrinsic (fabsf)

f32 Math3D_Normalize(Vec3f *v) {
    f32 mag;
    f32 inv;

    mag = Math3D_Vec3fMagnitude(v);
    if (fabsf(mag) < D_801D79C0) {
        return 0.0f;
    }
    inv = 1.0f / mag;
    v->x *= inv;
    v->y *= inv;
    v->z *= inv;
    return mag;
}
