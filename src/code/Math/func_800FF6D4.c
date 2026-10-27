// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

f32 sqrtf(f32);
#pragma intrinsic (sqrtf)

extern void Math_Vec3f_Diff(Vec3f *a, Vec3f *b, Vec3f *dest);

f32 Math_Vec3f_DistXYZAndStoreDiff(Vec3f *a, Vec3f *b, Vec3f *dest) {
    Math_Vec3f_Diff(b, a, dest);
    return sqrtf(dest->x * dest->x + dest->y * dest->y + dest->z * dest->z);
}
