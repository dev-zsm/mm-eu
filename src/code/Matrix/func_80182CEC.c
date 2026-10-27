#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    f32 mf[4][4];
} MtxF;

extern MtxF *D_801F3644;

void Matrix_MultVec3fXZ(Vec3f *src, Vec3f *dest) {
    MtxF *cmf = D_801F3644;

    dest->x = cmf->mf[0][0] * src->x + cmf->mf[1][0] * src->y + cmf->mf[2][0] * src->z + cmf->mf[3][0];
    dest->z = cmf->mf[0][2] * src->x + cmf->mf[1][2] * src->y + cmf->mf[2][2] * src->z + cmf->mf[3][2];
}
