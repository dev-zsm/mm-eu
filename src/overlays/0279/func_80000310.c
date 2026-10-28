// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800F0CC8(u8 *, M2C_UNK);                 /* extern */

void func_80000310(u8 *arg0, M2C_UNK arg1) {
    if (func_800F0CC8(arg0, 0x3F800000) != 0) {
        M2C_FIELD(arg0, s16 *, 0x1E8) = 0;
    }
}
