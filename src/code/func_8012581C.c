// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Matrix_Pop();                            /* extern */
extern s32 D_801C1618;

void func_8012581C(void) {
    if (D_801C1618 != 0) {
        Matrix_Pop();
        D_801C1618 = 0;
    }
}
