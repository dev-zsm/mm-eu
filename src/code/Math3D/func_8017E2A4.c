// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;

extern f32 D_801D7A24;
extern void Math3D_LineSplitRatio(Vec3f *a, Vec3f *b, f32 t, Vec3f *out);

float fabsf(float);
#pragma intrinsic (fabsf)

s32 Math3D_LineSegFindPlaneIntersect(f32 d0, f32 d1, Vec3f *a, Vec3f *b, Vec3f *out) {
    f32 diff = d0 - d1;

    if (fabsf(diff) < D_801D7A24) {
        *out = *b;
        return 0;
    }
    if (d0 == 0.0f) {
        *out = *a;
    } else if (d1 == 0.0f) {
        *out = *b;
    } else {
        Math3D_LineSplitRatio(a, b, d0 / diff, out);
    }
    return 1;
}
