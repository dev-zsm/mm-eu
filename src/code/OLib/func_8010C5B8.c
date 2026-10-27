#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3fC5B8;

void OLib_VecGeoToVec3f(Vec3fC5B8 *, void *);

Vec3fC5B8 *OLib_AddVecGeoToVec3f(Vec3fC5B8 *dest, Vec3fC5B8 *a, void *geo) {
    Vec3fC5B8 sum;
    Vec3fC5B8 b;

    OLib_VecGeoToVec3f(&b, geo);
    sum.x = a->x + b.x;
    sum.y = a->y + b.y;
    sum.z = a->z + b.z;
    *dest = sum;
    return dest;
}
