#include "types.h"
typedef struct { f32 x, y, z; } Vec3f;
extern f32 (*D_801F3644)[4];
void Matrix_MultVec3f(Vec3f *src, Vec3f *dest) {
    f32 (*mf)[4] = D_801F3644;
    dest->x = (mf[0][0] * src->x + mf[1][0] * src->y) + mf[2][0] * src->z + mf[3][0];
    dest->y = (mf[0][1] * src->x + mf[1][1] * src->y) + mf[2][1] * src->z + mf[3][1];
    dest->z = (mf[0][2] * src->x + mf[1][2] * src->y) + mf[2][2] * src->z + mf[3][2];
}
