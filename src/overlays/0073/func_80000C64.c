// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B7164(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800FEC70(s32, s16, M2C_UNK);           /* extern */
s32 func_801244EC(s32);                             /* extern */
s32 func_80137070(s32);                             /* extern */
M2C_UNK func_808931BC(u8 *, s32);                 /* extern */
M2C_UNK func_80893290(u8 *);                      /* extern */
M2C_UNK func_808935F4(u8 *);                      /* extern */
M2C_UNK func_80893D0C(u8 *);                      /* extern */

void func_80000C64(u8 *arg0, s32 arg1) {
    if (func_80137070(arg0 + 0x144) != 0) {
        if ((func_801244EC(arg1) == 0x10) || (M2C_FIELD(arg0, f32 *, 0x98) > 450.0f) || (M2C_FIELD(arg0, f32 *, 0x9C) > 80.0f)) {
            func_808935F4(arg0);
            return;
        }
        if (func_800B7164(arg0, 0x2328) == 0) {
            func_80893D0C(arg0);
            return;
        }
        func_808931BC(arg0, arg1);
        return;
    }
    func_800FEC70(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 0x5DC);
    func_80893290(arg0);
}
