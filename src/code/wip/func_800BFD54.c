#include "types.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    u16 type;
    u16 vtxA;
    u16 vtxB;
    u16 vtxC;
} CollisionPoly;

s16 CollisionPoly_GetMinY(CollisionPoly *poly, Vec3s *vertices) {
    s16 minY = vertices[poly->vtxA & 0x1FFF].y;

    if (vertices[poly->vtxB & 0x1FFF].y < minY) {
        minY = vertices[poly->vtxB & 0x1FFF].y;
    }
    if (minY < vertices[poly->vtxC & 0x1FFF].y) {
        return minY;
    }
    return vertices[poly->vtxC & 0x1FFF].y;
}
