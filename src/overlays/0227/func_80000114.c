// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A9868(M2C_UNK);                     /* extern */
s32 func_801A9910(M2C_UNK);                         /* extern */

void func_80000114(u8 *arg0) {
    if ((M2C_FIELD(arg0, s16 *, 0xA4) == 0x1D) && (func_801A9910(0) == 0x6F)) {
        func_801A9868(0x100100FF);
    }
}
