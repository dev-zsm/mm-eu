// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;

typedef struct {
    u8 pad0[0x40];
    s16 modelX, modelY, modelZ;
    s16 radius;
    s16 outX, outY, outZ;
    s16 outRadius;
    f32 scale;
    u8 pad54;
} Sphere;

extern f32 D_801E5AD0;
extern f32 D_801E5AD4;
extern f32 D_801E5AD8;
extern f32 D_801E5AE0;
extern f32 D_801E5AE4;
extern f32 D_801E5AE8;
extern void Matrix_MultVec3f(f32 *a, f32 *b, Sphere *c);

void Collider_UpdateSphere(s32 idx, Sphere *s) {
    if (idx == s->pad54) {
        D_801E5AD0 = s->modelX;
        D_801E5AD4 = s->modelY;
        D_801E5AD8 = s->modelZ;
        Matrix_MultVec3f(&D_801E5AD0, &D_801E5AE0, s);
        s->outX = D_801E5AE0;
        s->outY = D_801E5AE4;
        s->outZ = D_801E5AE8;
        s->outRadius = s->radius * s->scale;
    }
}
