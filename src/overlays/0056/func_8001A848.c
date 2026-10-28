// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D2D8(u8 *);                      /* extern */
M2C_UNK func_8083954C(u8 *, s32);                 /* extern */
M2C_UNK func_80847944(s32, u8 *);                 /* extern */

void func_8001A848(s32 arg0, u8 *arg1) {
    func_80847944(arg0, arg1);
    func_8082D2D8(arg1);
    func_8083954C(arg1, arg0);
    M2C_FIELD(arg1, s16 *, 0xAD4) = (s16) M2C_FIELD(arg1, s16 *, 0xBE);
}
