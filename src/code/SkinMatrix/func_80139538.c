// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skin_matrix.h"

s32 SkinMatrix_Invert(MtxF* src, MtxF* dest) {
    MtxF mfCopy;
    s32 i;
    f32 temp2;
    s32 thisRow;
    s32 thisCol;

    SkinMatrix_MtxFCopy(src, &mfCopy);
    SkinMatrix_Clear(dest);

    for (thisRow = 0; thisRow < 4; thisRow++) {
        thisCol = thisRow;
        while ((thisCol < 4) && (fabsf(mfCopy.mf[thisRow][thisCol]) < 0.0005f)) {
            thisCol++;
        }
        if (thisCol == 4) {
            
            
            return 2;
        }
        if (thisCol != thisRow) { 
            for (i = 0; i < 4; i++) {
                SWAP(f32, mfCopy.mf[i][thisCol], mfCopy.mf[i][thisRow]);
                SWAP(f32, dest->mf[i][thisCol], dest->mf[i][thisRow]);
            }
        }

        
        temp2 = mfCopy.mf[thisRow][thisRow];
        for (i = 0; i < 4; i++) {
            mfCopy.mf[i][thisRow] /= temp2;
            dest->mf[i][thisRow] /= temp2;
        }

        for (thisCol = 0; thisCol < 4; thisCol++) {
            if (thisCol != thisRow) {
                temp2 = mfCopy.mf[thisRow][thisCol];
                for (i = 0; i < 4; i++) {
                    mfCopy.mf[i][thisCol] -= mfCopy.mf[i][thisRow] * temp2;
                    dest->mf[i][thisCol] -= dest->mf[i][thisRow] * temp2;
                }
            }
        }
    }

    return 0;
}
