#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct { u8 pad0[0xE]; s16 dist; } Poly;

extern Vec3f D_801E5220[3];
extern void CollisionPoly_GetVertices(Poly *, void *, Vec3f *);
extern void CollisionPoly_GetNormalF(Poly *, f32 *, f32 *, f32 *);
extern s32 Math3D_TriChkPointParaZIntersect(Vec3f *, Vec3f *, Vec3f *, f32, f32, f32, f32, f32, f32, s32);

s32 CollisionPoly_CheckZIntersectApprox(Poly *poly, void *vtx, f32 x, f32 y, s32 a5) {
    f32 nx, ny, nz;

    CollisionPoly_GetVertices(poly, vtx, D_801E5220);
    CollisionPoly_GetNormalF(poly, &nx, &ny, &nz);
    return Math3D_TriChkPointParaZIntersect(&D_801E5220[0], &D_801E5220[1], &D_801E5220[2], nx, ny, nz, poly->dist, x, y, a5);
}
