// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;

extern f32 Math3D_Cos(Vec3f *a, Vec3f *b);

void Math3D_Vec3fReflect(Vec3f *vec, Vec3f *normal, Vec3f *reflVec) {
    f32 pad;
    Vec3f neg;
    f32 sp24;
    f32 dot;
    f32 sx;
    f32 sy;

    neg.x = vec->x * -1.0f;
    neg.y = vec->y * -1.0f;
    neg.z = vec->z * -1.0f;
    dot = Math3D_Cos(&neg, normal);
    sx = normal->x * dot;
    sy = normal->y * dot;
    sp24 = normal->z * dot;
    reflVec->x = 2.0f * (vec->x + sx) + neg.x;
    reflVec->y = 2.0f * (vec->y + sy) + neg.y;
    reflVec->z = 2.0f * (vec->z + sp24) + neg.z;
}
