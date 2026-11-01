#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

extern void Math_Vec3f_Diff(Vec3f *a, Vec3f *b, Vec3f *dest);

float sqrtf(float);
#pragma intrinsic (sqrtf)

f32 Math_Vec3f_DistXYZ(Vec3f *a, Vec3f *b) {
    Vec3f diff;

    Math_Vec3f_Diff(b, a, &diff);
    return sqrtf((diff.x * diff.x) + (diff.y * diff.y) + (diff.z * diff.z));
}
