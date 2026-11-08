// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern s32 D_801F3644;

void Matrix_Mult(union MtxF *mf, s32 mode) {
    s32 temp_v0;

    temp_v0 = Matrix_GetCurrent();
    if (mode == 1) {
        SkinMatrix_MtxFMtxFMult(temp_v0, mf, temp_v0);
        return;
    }
    Matrix_MtxFCopy(D_801F3644, mf);
}
