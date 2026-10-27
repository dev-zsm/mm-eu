#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;

f32 func_80086BA0(f32 a, f32 b);

Vec3f OLib_Vec3fDiffRad(Vec3f *a, Vec3f *b) {
    Vec3f r;

    r.x = func_80086BA0(b->z - a->z, b->y - a->y);
    r.y = func_80086BA0(b->x - a->x, b->z - a->z);
    r.z = 0.0f;
    return r;
}
