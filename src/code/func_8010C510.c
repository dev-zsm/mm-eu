#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

extern void OLib_Vec3fToVecSph(void *sph, Vec3f *vec);

void OLib_Vec3fDiffToVecSph(Vec3f *dest, Vec3f *a, Vec3f *b) {
    Vec3f diff;

    diff.x = b->x - a->x;
    diff.y = b->y - a->y;
    diff.z = b->z - a->z;
    OLib_Vec3fToVecSph(dest, &diff);
}
