// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1D6C(s8);                          /* extern */

s32 func_80000DE0(u8 *arg0, M2C_UNK arg1) {
    func_800F1D6C(M2C_FIELD(arg0, s8 *, 0x2B2));
    M2C_FIELD(arg0, s8 *, 0x2B1) = 0;
    return 0;
}
