// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

extern M2C_UNK D_801C6990;

void SkinMatrix_GetClear(union MtxF **mfp) {
    *mfp = &D_801C6990;
}
