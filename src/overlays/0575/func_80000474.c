// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5C88(M2C_UNK, s8, M2C_UNK);            /* extern */
M2C_UNK func_80BBA8E4(u8 *);                      /* extern */

void func_80000474(u8 *arg0, M2C_UNK arg1) {
    if (func_800B5C88(arg1, M2C_FIELD(arg0, s8 *, 3), arg1) != 0) {
        func_80BBA8E4(arg0);
    }
}
