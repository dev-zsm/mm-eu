// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    Vec3f v[3];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
} Tri;

s32 func_8017C908(Vec3f *a, Vec3f *b, Vec3f *c, f32 *d, f32 *e, f32 *f, f32 *g);

s32 Collider_SetTrisElementDim(s32 arg0, Tri *dst, Vec3f *src) {
    Vec3f *p;
    Vec3f *q;
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    for (p = dst->v, q = src; p < &dst->v[3]; p++, q++) {
        *p = *q;
    }
    func_8017C908(&src[0], &src[1], &src[2], &a, &b, &c, &d);
    dst->unk24 = a;
    dst->unk28 = b;
    dst->unk2C = c;
    dst->unk30 = d;
    return 1;
}
