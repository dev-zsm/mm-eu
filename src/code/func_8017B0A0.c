#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

void Math3D_PointOnDirectedLine(Vec3f *a, Vec3f *b, f32 scale, Vec3f *dest) {
    dest->x = b->x * scale + a->x;
    dest->y = b->y * scale + a->y;
    dest->z = b->z * scale + a->z;
}
