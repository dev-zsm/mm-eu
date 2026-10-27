#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    s16 x, y, z;
} Vec3s;

Vec3f *Camera_Vec3sToVec3f(Vec3f *dest, Vec3s *src) {
    Vec3f copy;

    copy.x = src->x;
    copy.y = src->y;
    copy.z = src->z;
    *dest = copy;
    return dest;
}
