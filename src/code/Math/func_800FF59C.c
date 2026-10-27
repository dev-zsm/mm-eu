#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern f32 Rand_CenteredFloat(f32 scale);

void Math_Vec3f_AddRand(Vec3f *pos, f32 randScale, Vec3f *dst) {
    dst->x = Rand_CenteredFloat(randScale) + pos->x;
    dst->y = Rand_CenteredFloat(randScale) + pos->y;
    dst->z = Rand_CenteredFloat(randScale) + pos->z;
}
