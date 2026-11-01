#include "types.h"

typedef struct {
    f32 mf[4][4];
} MtxF;

typedef struct {
    f32 x, y, z;
} Vec3f;

extern MtxF *D_801F3644;

void Matrix_MultVecZ(f32 z, Vec3f *dest) {
    MtxF *cur = D_801F3644;

    dest->x = cur->mf[3][0] + cur->mf[2][0] * z;
    dest->y = cur->mf[3][1] + cur->mf[2][1] * z;
    dest->z = cur->mf[3][2] + cur->mf[2][2] * z;
}
