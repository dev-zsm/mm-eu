// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_matrix_ctx.h"

void Matrix_MtxFToZYXRot(MtxF* src, Vec3s* dest, s32 nonUniformScale) {
    f32 temp;
    f32 temp2;
    f32 temp3;
    f32 temp4;

    temp = src->xx;
    temp *= temp;
    temp += SQ(src->yx);
    dest->y = Math_Atan2S(-src->zx, sqrtf(temp));

    if ((dest->y == 0x4000) || (dest->y == -0x4000)) {
        dest->x = 0;
        dest->z = Math_Atan2S(-src->xy, src->yy);
    } else {
        dest->z = Math_Atan2S(src->yx, src->xx);

        if (!nonUniformScale) {
            dest->x = Math_Atan2S(src->zy, src->zz);
        } else {
            temp = src->xy;
            temp2 = src->yy;
            temp3 = src->yz;

            temp *= temp;
            temp += SQ(temp2);
            temp2 = src->zy;
            temp += SQ(temp2);
            temp = sqrtf(temp);
            temp = temp2 / temp;

            temp2 = src->xz;
            temp2 *= temp2;
            temp2 += SQ(temp3);
            temp3 = src->zz;
            temp2 += SQ(temp3);
            temp2 = sqrtf(temp2);
            temp2 = temp3 / temp2;

            dest->x = Math_Atan2S(temp, temp2);
        }
    }
}
