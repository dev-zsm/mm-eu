// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "code_funcs.h"
extern void *D_801F3644;
void Matrix_Get(s32 a0) {
    Matrix_MtxFCopy(a0, D_801F3644);
}
