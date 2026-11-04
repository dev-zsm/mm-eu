// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

void Math_Vec3f_Copy(Vec3f *dst, Vec3f *src) {
    f32 x = src->x;
    f32 y = src->y;
    f32 z = src->z;

    dst->x = x;
    dst->y = y;
    dst->z = z;
}
