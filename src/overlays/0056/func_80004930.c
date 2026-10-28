// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1B24(s16, u8 *);                 /* extern */
s32 func_800F1E2C();                                /* extern */

s32 func_80004930(u8 *arg0, s16 arg1) {
    if ((arg1 >= 0) && (func_800F1E2C() != arg1)) {
        if (func_800F1984(arg1) == 0) {
            func_800F1944(arg1);
            return 0;
        }
        func_800F1B24(arg1, arg0);
        goto block_5;
    }
block_5:
    M2C_FIELD(arg0, s8 *, 0xA86) = (s8) arg1;
    return 1;
}
