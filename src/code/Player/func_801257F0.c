// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Matrix_Push();                            /* extern */
extern s32 D_801C1618;

void func_801257F0(void) {
    Matrix_Push();
    D_801C1618 = 1;
}
