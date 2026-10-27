#include "types.h"

typedef struct {
    u8 pad0[8];
    s16 normalX;
    s16 normalY;
    s16 normalZ;
    s16 dist;
} CollisionPoly;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern f32 D_801D4DC4;

f32 CollisionPoly_GetPointDistanceFromPlane(CollisionPoly *poly, Vec3f *point) {
    return ((poly->normalX * point->x + poly->normalY * point->y + poly->normalZ * point->z) * D_801D4DC4) + poly->dist;
}
