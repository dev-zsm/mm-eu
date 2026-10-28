// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;
extern f32 D_801D5B70;
f32 OLib_ClampMinDist(f32 a, f32 b);
float sqrtf(float);
#pragma intrinsic (sqrtf)
void OLib_Vec3fDistNormalize(Vec3f *dst, Vec3f *a, Vec3f *b) {
    Vec3f d;
    Vec3f r;
    f32 m;
    d.x = b->x - a->x;
    d.y = b->y - a->y;
    d.z = b->z - a->z;
    m = OLib_ClampMinDist(sqrtf(((d.x * d.x) + (d.y * d.y)) + (d.z * d.z)), D_801D5B70);
    r.x = d.x / m;
    r.y = d.y / m;
    r.z = d.z / m;
    if (dst) {
    }
    *dst = r;
}
