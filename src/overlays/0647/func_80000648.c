// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B763C(s32, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80C021F8(u8 *);                      /* extern */
M2C_UNK func_80C02480(u8 *, s32);                 /* extern */

void func_80000648(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x188)(arg0, arg1);
    func_80C02480(arg0, arg1);
    func_80137070(arg0 + 0x144);
    func_80C021F8(arg0);
    func_800B763C(arg1, arg0, 0x41F00000, 0x41400000, 0.0f, 4);
}
