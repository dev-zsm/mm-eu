// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Matrix_GetCurrent(void);
void SkinMatrix_MtxFMtxFMult(s32, s32, s32);
void Matrix_MtxFCopy(s32, s32);
extern s32 D_801F3644;

void Matrix_Mult(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = Matrix_GetCurrent();
    if (arg1 == 1) {
        SkinMatrix_MtxFMtxFMult(temp_v0, arg0, temp_v0);
        return;
    }
    Matrix_MtxFCopy(D_801F3644, arg0);
}
