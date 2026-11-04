// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skin_matrix.h"

void SkinMatrix_MtxFMtxFMult(MtxF* mfB, MtxF* mfA, MtxF* dest) {
    f32 rx;
    f32 ry;
    f32 rz;
    f32 rw;

    
    f32 cx = mfB->xx;
    f32 cy = mfB->xy;
    f32 cz = mfB->xz;
    f32 cw = mfB->xw;
    

    rx = mfA->xx;
    ry = mfA->yx;
    rz = mfA->zx;
    rw = mfA->wx;
    dest->xx = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    rx = mfA->xy;
    ry = mfA->yy;
    rz = mfA->zy;
    rw = mfA->wy;
    dest->xy = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    rx = mfA->xz;
    ry = mfA->yz;
    rz = mfA->zz;
    rw = mfA->wz;
    dest->xz = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    rx = mfA->xw;
    ry = mfA->yw;
    rz = mfA->zw;
    rw = mfA->ww;
    dest->xw = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    
    cx = mfB->yx;
    cy = mfB->yy;
    cz = mfB->yz;
    cw = mfB->yw;
    
    rx = mfA->xx;
    ry = mfA->yx;
    rz = mfA->zx;
    rw = mfA->wx;
    dest->yx = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    rx = mfA->xy;
    ry = mfA->yy;
    rz = mfA->zy;
    rw = mfA->wy;
    dest->yy = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    rx = mfA->xz;
    ry = mfA->yz;
    rz = mfA->zz;
    rw = mfA->wz;
    dest->yz = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    rx = mfA->xw;
    ry = mfA->yw;
    rz = mfA->zw;
    rw = mfA->ww;
    dest->yw = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    
    cx = mfB->zx;
    cy = mfB->zy;
    cz = mfB->zz;
    cw = mfB->zw;
    
    rx = mfA->xx;
    ry = mfA->yx;
    rz = mfA->zx;
    rw = mfA->wx;
    dest->zx = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    rx = mfA->xy;
    ry = mfA->yy;
    rz = mfA->zy;
    rw = mfA->wy;
    dest->zy = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    rx = mfA->xz;
    ry = mfA->yz;
    rz = mfA->zz;
    rw = mfA->wz;
    dest->zz = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    rx = mfA->xw;
    ry = mfA->yw;
    rz = mfA->zw;
    rw = mfA->ww;
    dest->zw = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    
    cx = mfB->wx;
    cy = mfB->wy;
    cz = mfB->wz;
    cw = mfB->ww;
    
    rx = mfA->xx;
    ry = mfA->yx;
    rz = mfA->zx;
    rw = mfA->wx;
    dest->wx = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    rx = mfA->xy;
    ry = mfA->yy;
    rz = mfA->zy;
    rw = mfA->wy;
    dest->wy = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    rx = mfA->xz;
    ry = mfA->yz;
    rz = mfA->zz;
    rw = mfA->wz;
    dest->wz = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);

    rx = mfA->xw;
    ry = mfA->yw;
    rz = mfA->zw;
    rw = mfA->ww;
    dest->ww = (cx * rx) + (cy * ry) + (cz * rz) + (cw * rw);
}
