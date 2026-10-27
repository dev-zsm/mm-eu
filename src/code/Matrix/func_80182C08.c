#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    f32 xx, yx, zx, wx;
    f32 xy, yy, zy, wy;
    f32 xz, yz, zz, wz;
    f32 xw, yw, zw, ww;
} MtxF;

extern MtxF *D_801F3644;

void Matrix_MultVecX(f32 x, Vec3f *dest) {
    MtxF *mf = D_801F3644;

    dest->x = mf->xw + mf->xx * x;
    dest->y = mf->yw + mf->yx * x;
    dest->z = mf->zw + mf->zx * x;
}
