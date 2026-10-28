// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8016A844(s32, s16);                        /* extern */
M2C_UNK func_8016A87C(s32, s16, u8 *, s32);       /* extern */

void func_800019EC(u8 *arg0, s32 arg1) {
    func_8016A87C(arg1, M2C_FIELD(arg0, s16 *, 0x2C6), arg0 + 0x3C, func_8016A844(arg1, M2C_FIELD(arg0, s16 *, 0x2C6)) + 0x5C);
}
