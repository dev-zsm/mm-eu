// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801C6990;

void SkinMatrix_GetClear(M2C_UNK **arg0) {
    *arg0 = &D_801C6990;
}
