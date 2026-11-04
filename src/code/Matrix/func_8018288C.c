// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_matrix_ctx.h"

Mtx* Matrix_MtxFToMtx(MtxF* src, Mtx* dest) {
    s32 temp;
    u16* intPart = (u16*)&dest->m[0][0];
    u16* fracPart = (u16*)&dest->m[2][0];

    
    temp = src->xx * 0x10000;
    intPart[0] = (temp >> 0x10);
    intPart[16 + 0] = temp;

    temp = src->yx * 0x10000;
    intPart[1] = (temp >> 0x10);
    intPart[16 + 1] = temp;

    temp = src->zx * 0x10000;
    intPart[2] = (temp >> 0x10);
    intPart[16 + 2] = temp;

    temp = src->wx * 0x10000;
    intPart[3] = (temp >> 0x10);
    intPart[16 + 3] = temp;

    temp = src->xy * 0x10000;
    intPart[4] = (temp >> 0x10);
    intPart[16 + 4] = temp;

    temp = src->yy * 0x10000;
    intPart[5] = (temp >> 0x10);
    intPart[16 + 5] = temp;

    temp = src->zy * 0x10000;
    intPart[6] = (temp >> 0x10);
    intPart[16 + 6] = temp;

    temp = src->wy * 0x10000;
    intPart[7] = (temp >> 0x10);
    intPart[16 + 7] = temp;

    temp = src->xz * 0x10000;
    intPart[8] = (temp >> 0x10);
    intPart[16 + 8] = temp;

    temp = src->yz * 0x10000;
    intPart[9] = (temp >> 0x10);
    fracPart[9] = temp;

    temp = src->zz * 0x10000;
    intPart[10] = (temp >> 0x10);
    fracPart[10] = temp;

    temp = src->wz * 0x10000;
    intPart[11] = (temp >> 0x10);
    fracPart[11] = temp;

    temp = src->xw * 0x10000;
    intPart[12] = (temp >> 0x10);
    fracPart[12] = temp;

    temp = src->yw * 0x10000;
    intPart[13] = (temp >> 0x10);
    fracPart[13] = temp;

    temp = src->zw * 0x10000;
    intPart[14] = (temp >> 0x10);
    fracPart[14] = temp;

    temp = src->ww * 0x10000;
    intPart[15] = (temp >> 0x10);
    fracPart[15] = temp;

    return dest;
}
