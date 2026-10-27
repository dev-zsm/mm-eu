// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    s16 x, y, z;
} Vec3s;

f32 Math3D_Vec3fMagnitude(Vec3f *vec);

f32 func_8017B9F0(Vec3s *a, Vec3f *b) {
    Vec3f diff;

    diff.x = a->x - b->x;
    diff.y = a->y - b->y;
    diff.z = a->z - b->z;
    return Math3D_Vec3fMagnitude(&diff);
}
