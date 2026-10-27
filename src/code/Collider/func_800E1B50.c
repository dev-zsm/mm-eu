#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    Vec3f quad[4];
} QuadDim;

extern void Collider_SetQuadMidpoints(QuadDim* dim);

s32 Collider_SetQuadDim(void* play, QuadDim* dim, QuadDim* src) {
    dim->quad[0] = src->quad[0];
    dim->quad[1] = src->quad[1];
    dim->quad[2] = src->quad[2];
    dim->quad[3] = src->quad[3];
    Collider_SetQuadMidpoints(dim);
    return 1;
}
