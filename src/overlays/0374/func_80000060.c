// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A796E4(s32);                         /* extern */

s32 func_80000060(s32 arg0, u8 *arg1) {
    func_80A796E4(M2C_FIELD(arg1, s32 *, 0x48));
    return 0;
}
