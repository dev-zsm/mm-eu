// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

f32 Math_Vec3f_DistXYZAndStoreDiff(Vec3f *a, Vec3f *b, Vec3f *dest);

void Math_Vec3f_DistXYZAndStoreNormDiff(Vec3f *a, Vec3f *b, f32 scale, Vec3f *dest) {
    f32 dist = Math_Vec3f_DistXYZAndStoreDiff(a, b, dest);
    f32 f;

    if (dist != 0.0f) {
        f = scale / dist;
        dest->x *= f;
        dest->y *= f;
        dest->z *= f;
    }

}
