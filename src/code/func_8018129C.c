// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Matrix_MtxFCopy(s32, s32);                    /* extern */
extern s32 D_801F3644;

void Matrix_Put(s32 arg0) {
    Matrix_MtxFCopy(D_801F3644, arg0);
}
