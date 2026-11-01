#include "types.h"
#include "generated/code_funcs.h"

typedef struct {
    f32 mf[4][4];
} MtxF;

extern MtxF *D_801F3644;
void Matrix_MtxFCopy();

void Matrix_Push(void) {
    MtxF *prev = D_801F3644;

    Matrix_MtxFCopy(++D_801F3644, prev);
}
