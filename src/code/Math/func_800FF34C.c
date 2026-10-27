#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    s16 x, y, z;
} Vec3s;

void Math_Vec3s_ToVec3f(Vec3f *dest, Vec3s *src) {
    f32 x = src->x;
    f32 y = src->y;
    f32 z = src->z;

    dest->x = x;
    dest->y = y;
    dest->z = z;
}
