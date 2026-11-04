// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_matrix_ctx.h"

void Matrix_MtxToMtxF(Mtx* src, MtxF* dest) {
    u16* intPart = (u16*)&src->m[0][0];
    u16* fracPart = (u16*)&src->m[2][0];

    dest->xx = ((intPart[0] << 0x10) | fracPart[0]) * (1 / (f32)0x10000);
    dest->yx = ((intPart[1] << 0x10) | fracPart[1]) * (1 / (f32)0x10000);
    dest->zx = ((intPart[2] << 0x10) | fracPart[2]) * (1 / (f32)0x10000);
    dest->wx = ((intPart[3] << 0x10) | fracPart[3]) * (1 / (f32)0x10000);
    dest->xy = ((intPart[4] << 0x10) | fracPart[4]) * (1 / (f32)0x10000);
    dest->yy = ((intPart[5] << 0x10) | fracPart[5]) * (1 / (f32)0x10000);
    dest->zy = ((intPart[6] << 0x10) | fracPart[6]) * (1 / (f32)0x10000);
    dest->wy = ((intPart[7] << 0x10) | fracPart[7]) * (1 / (f32)0x10000);
    dest->xz = ((intPart[8] << 0x10) | fracPart[8]) * (1 / (f32)0x10000);
    dest->yz = ((intPart[9] << 0x10) | fracPart[9]) * (1 / (f32)0x10000);
    dest->zz = ((intPart[10] << 0x10) | fracPart[10]) * (1 / (f32)0x10000);
    dest->wz = ((intPart[11] << 0x10) | fracPart[11]) * (1 / (f32)0x10000);
    dest->xw = ((intPart[12] << 0x10) | fracPart[12]) * (1 / (f32)0x10000);
    dest->yw = ((intPart[13] << 0x10) | fracPart[13]) * (1 / (f32)0x10000);
    dest->zw = ((intPart[14] << 0x10) | fracPart[14]) * (1 / (f32)0x10000);
    dest->ww = ((intPart[15] << 0x10) | fracPart[15]) * (1 / (f32)0x10000);
}
