// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 xx, yx, zx, wx, xy, yy, zy, wy, xz, yz, zz, wz, xw, yw, zw, ww; } MtxF;
void Matrix_MultVec3fExt(V3 *src, V3 *dest, MtxF *mf) {
    dest->x = mf->xw + (mf->xx * src->x + mf->xy * src->y + mf->xz * src->z);
    dest->y = mf->yw + (mf->yx * src->x + mf->yy * src->y + mf->yz * src->z);
    dest->z = mf->zw + (mf->zx * src->x + mf->zy * src->y + mf->zz * src->z);
}
