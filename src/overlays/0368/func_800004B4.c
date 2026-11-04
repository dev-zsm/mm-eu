// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_SetMatrixRotation(ObjMineMtxF3* basis) {
    MtxF* matrix = Matrix_GetCurrent();

    matrix->xx = basis->x.x;
    matrix->yx = basis->x.y;
    matrix->zx = basis->x.z;
    matrix->wx = 0.0f;

    matrix->xy = basis->y.x;
    matrix->yy = basis->y.y;
    matrix->zy = basis->y.z;
    matrix->wy = 0.0f;

    matrix->xz = basis->z.x;
    matrix->yz = basis->z.y;
    matrix->zz = basis->z.z;
    matrix->wz = 0.0f;

    matrix->xw = 0.0f;
    matrix->yw = 0.0f;
    matrix->zw = 0.0f;
    matrix->ww = 1.0f;
}
