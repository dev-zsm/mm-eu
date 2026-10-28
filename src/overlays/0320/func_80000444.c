// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80A1D05C(u8 *, s32);                 /* extern */
M2C_UNK func_80A1D1B8(u8 *);                      /* extern */

void func_80000444(u8 *arg0, s32 arg1) {
    func_80A1D1B8(arg0);
    func_80137070(arg0 + 0x144);
    func_80A1D05C(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x260)(arg0, arg1);
}
