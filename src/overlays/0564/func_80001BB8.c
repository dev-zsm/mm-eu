// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80BAFC18(u8 *, s32);                 /* extern */

void func_80001BB8(u8 *arg0, s32 arg1) {
    func_800B64E0(arg0, 0x42700000);
    func_80137070(arg0 + 0x144);
    func_800B680C(arg0);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x2D8)(arg0, arg1);
    if (M2C_FIELD(arg0, u16 *, 0x328) & 8) {
        func_800B8D94(arg0, 0x3285);
    }
    func_80BAFC18(arg0, arg1);
}
