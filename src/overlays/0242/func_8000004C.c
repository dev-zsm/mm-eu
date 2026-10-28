// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A23EC(M2C_UNK, M2C_UNK);            /* extern */

void func_8000004C(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x146) == 1) {
        func_801A23EC(0, 0);
    }
}
