#include "types.h"

void SkinMatrix_Vec3fMtxFMultXYZ(f32 *mf, f32 *src, f32 *dest) {
    f32 x = src[0];
    f32 y = src[1];
    f32 z = src[2];
    dest[0] = mf[0] * x + mf[4] * y + mf[8] * z + mf[12];
    dest[1] = mf[1] * x + mf[5] * y + mf[9] * z + mf[13];
    dest[2] = mf[2] * x + mf[6] * y + mf[10] * z + mf[14];
}
