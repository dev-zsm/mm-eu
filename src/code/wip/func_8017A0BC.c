// FLAGS: -O2 -g3 -mips2
// STATUS: automatic draft, 6/16 instructions differ
#include "types.h"
#include "m2c_compat.h"

s32 func_800809A0();                                /* extern */
M2C_UNK func_8017A02C(s32, s32, s32, s32);          /* extern */

void func_8017A0BC(s32 arg1, s32 arg2, s32 arg3) {
    func_8017A02C(func_800809A0(), arg1, arg2, arg3);
}
