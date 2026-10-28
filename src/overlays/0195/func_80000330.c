// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800A8A34(s32);                         /* extern */
s32 func_800AFC40(s32, u8 *);                     /* extern */

void func_80000330(u8 *arg0) {
    func_800A8A34(func_800AFC40(M2C_FIELD(arg0, s32 *, 0x530), arg0));
}
