#include "types.h"

extern u8 D_801E53F0[], D_801E53FC[], D_801E5408[];
extern void CollisionPoly_GetVertices(void *a, s32 b, void *c);
extern void CollisionPoly_GetNormalF(void *a, void *b, void *c, void *d);
extern void Math3D_TriChkPointParaXIntersect(void *a, void *b, void *c, s32 d, f32 e, f32 f, f32 g, f32 h, f32 i, s32 j);
typedef struct { u8 pad0[0xE]; s16 unkE; } Poly;

void CollisionPoly_CheckXIntersectApprox(Poly *poly, s32 unused, f32 a, f32 b, s32 c) {
    s32 s3C;
    f32 s38;
    f32 s34;

    CollisionPoly_GetVertices(poly, unused, D_801E53F0);
    CollisionPoly_GetNormalF(poly, &s3C, &s38, &s34);
    Math3D_TriChkPointParaXIntersect(D_801E53F0, D_801E53FC, D_801E5408, s3C, s38, s34, poly->unkE, a, b, c);
}
