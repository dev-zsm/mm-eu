// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80BF9AB4(u8 *, s32);                 /* extern */
M2C_UNK func_80BF9AF8(u8 *, s32);                 /* extern */

void func_800014D8(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x1D4)(arg0, arg1);
    func_80137070(arg0 + 0x190);
    func_80BF9AB4(arg0, arg1);
    func_80BF9AF8(arg0, arg1);
}
