// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern void *D_801F3644;
extern void Matrix_MtxFCopy();
void Matrix_Get(s32 a0) {
    Matrix_MtxFCopy(a0, D_801F3644);
}
