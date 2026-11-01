#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern float sqrtf(float);
#pragma intrinsic (sqrtf)

f32 OLib_Vec3fDist(Vec3f *a, Vec3f *b) {
    f32 dx = a->x - b->x;
    f32 dy = a->y - b->y;
    f32 dz = a->z - b->z;

    return sqrtf(dx * dx + dy * dy + dz * dz);
}
