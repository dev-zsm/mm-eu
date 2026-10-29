#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    f32 m[4][4];
} MtxF;

void SkinMatrix_Vec3fMtxFMultXYZW(MtxF *mf, Vec3f *src, Vec3f *xyzDest, f32 *wDest) {
    xyzDest->x = (src->x * mf->m[0][0] + src->y * mf->m[1][0] + src->z * mf->m[2][0]) + mf->m[3][0];
    xyzDest->y = (src->x * mf->m[0][1] + src->y * mf->m[1][1] + src->z * mf->m[2][1]) + mf->m[3][1];
    xyzDest->z = (src->x * mf->m[0][2] + src->y * mf->m[1][2] + src->z * mf->m[2][2]) + mf->m[3][2];
    *wDest = (src->x * mf->m[0][3] + src->y * mf->m[1][3] + src->z * mf->m[2][3]) + mf->m[3][3];
}
