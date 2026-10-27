#include "types.h"

typedef struct {
    u8 pad0[8];
    s16 nx;
    s16 ny;
    s16 nz;
} CollisionPoly;

void CollisionPoly_GetNormalF(CollisionPoly *poly, f32 *nx, f32 *ny, f32 *nz) {
    *nx = poly->nx * (1.0f / 32767.0f);
    *ny = poly->ny * (1.0f / 32767.0f);
    *nz = poly->nz * (1.0f / 32767.0f);
}
