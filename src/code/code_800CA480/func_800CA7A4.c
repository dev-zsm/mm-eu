// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0xE];
    s16 unkE;
} Obj;

void CollisionPoly_GetNormalF(Obj *o, f32 *x, f32 *y, f32 *z);
void Math3D_PlaneVsLineSegClosestPoint(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h, s32 i, s32 j, s32 k);

void func_800CA7A4(Obj *a0, Obj *a1, s32 a2, s32 a3, s32 a4) {
    f32 x0;
    f32 y0;
    f32 z0;
    f32 x1;
    f32 y1;
    f32 z1;
    s32 pad[2]; // unused, matches the frame size


    CollisionPoly_GetNormalF(a0, &x0, &y0, &z0);
    CollisionPoly_GetNormalF(a1, &x1, &y1, &z1);
    Math3D_PlaneVsLineSegClosestPoint(x0, y0, z0, (f32)a0->unkE, x1, y1, z1, (f32)a1->unkE, a2, a3, a4);
}
