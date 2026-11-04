// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_matrix_ctx.h"

void Matrix_MtxFToYXZRot(MtxF* src, Vec3s* dest, s32 nonUniformScale) {
    f32 temp;
    f32 temp2;
    f32 temp3;
    f32 temp4;

    temp = src->xz;
    temp *= temp;
    temp += SQ(src->zz);
    dest->x = Math_Atan2S(-src->yz, sqrtf(temp));

    if ((dest->x == 0x4000) || (dest->x == -0x4000)) {
        
        
        
        dest->z = 0;

        dest->y = Math_Atan2S(-src->zx, src->xx);
    } else {
        dest->y = Math_Atan2S(src->xz, src->zz);

        if (!nonUniformScale) {
            
            dest->z = Math_Atan2S(src->yx, src->yy);
        } else {
            temp = src->xx;
            temp2 = src->zx;
            temp3 = src->zy;

            
            temp *= temp;
            temp += SQ(temp2);
            temp2 = src->yx;
            temp += SQ(temp2);
            
            temp = sqrtf(temp);
            temp = temp2 / temp; 

            
            temp2 = src->xy;
            temp2 *= temp2;
            temp2 += SQ(temp3);
            temp3 = src->yy;
            temp2 += SQ(temp3);
            
            temp2 = sqrtf(temp2);
            temp2 = temp3 / temp2; 

            
            dest->z = Math_Atan2S(temp, temp2);
        }
    }
}
