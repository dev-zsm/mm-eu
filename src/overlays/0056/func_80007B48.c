// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D8A0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8082DC9C(s32, u8 *, s32);            /* extern */
M2C_UNK func_80833150(u8 *, s32);                 /* extern */

void func_80007B48(s32 arg0, u8 *arg1, s32 arg2) {
    func_80833150(arg1, arg0);
    M2C_FIELD(arg1, s16 *, 0xAE8) = -2;
    func_8082DC9C(arg0, arg1, arg2);
    func_8082D8A0(arg1, 0x1852);
}
