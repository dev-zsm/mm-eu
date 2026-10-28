// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF30C(s32, s32, u8 *);            /* extern */

void func_8000188C(u8 *arg0) {
    func_800FF30C(arg0 + 8, arg0 + 0x24, arg0);
    M2C_FIELD(arg0, s16 *, 0x278) = 0;
    M2C_FIELD(arg0, s16 *, 0x276) = (s16) M2C_FIELD(arg0, s16 *, 0x278);
}
