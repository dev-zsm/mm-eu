// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80985560(u8 *, s32);                 /* extern */
M2C_UNK func_809855E4(u8 *, s32);                 /* extern */

void func_80000A70(u8 *arg0, s32 arg1) {
    func_80985560(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x31C)(arg0, arg1);
    func_809855E4(arg0, arg1);
}
