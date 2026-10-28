// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s8 func_800F1E68(s8);                               /* extern */

s32 func_80001604(u8 *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_FIELD(arg0, s8 *, 0xD8D) = func_800F1E68(M2C_FIELD(arg0, s8 *, 0x38));
    return 1;
}
