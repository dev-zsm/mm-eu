// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

float sqrtf(float);
#pragma intrinsic (sqrtf)

f32 OLib_Vec3fDistOutDiff(Vec3f *a, Vec3f *b, Vec3f *diff) {
    diff->x = a->x - b->x;
    diff->y = a->y - b->y;
    diff->z = a->z - b->z;
    return sqrtf(diff->x * diff->x + diff->y * diff->y + diff->z * diff->z);
}
