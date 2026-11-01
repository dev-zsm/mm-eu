// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Matrix_ToMtx(s32, void *);                 /* extern */

void Matrix_Finalize(void *arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x2B4) - 0x40;
    M2C_FIELD(arg0, s32 *, 0x2B4) = temp_a0;
    Matrix_ToMtx(temp_a0, arg0);
}
