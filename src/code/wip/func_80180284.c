#include "types.h"

typedef struct { s16 x, y, z; } Vec3s;
typedef struct {
    Vec3s center;
    s16 radius;
} Sph16;

extern f32 D_801D7A58;
float sqrtf(float);
#pragma intrinsic (sqrtf)

s32 Math3D_SphVsSphOverlapCenterDist(Sph16 *a, Sph16 *b, f32 *overlap, f32 *centerDist) {
    f32 dx = (f32)a->center.x - (f32)b->center.x;
    f32 dy = (f32)a->center.y - (f32)b->center.y;
    f32 dz = (f32)a->center.z - (f32)b->center.z;

    *centerDist = sqrtf(dx * dx + dy * dy + dz * dz);
    *overlap = (f32)a->radius + (f32)b->radius - *centerDist;
    if (*overlap > D_801D7A58) {
        return 1;
    }
    *overlap = 0.0f;
    return 0;
}
