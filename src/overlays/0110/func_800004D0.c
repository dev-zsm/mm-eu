// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B7164(u8 *, M2C_UNK);                 /* extern */
s32 func_80137070(s32);                             /* extern */
M2C_UNK func_808D02E4(u8 *);                      /* extern */
M2C_UNK func_808D075C(u8 *);                      /* extern */
M2C_UNK func_808D0A50(u8 *, s32);                 /* extern */

void func_800004D0(u8 *arg0, s32 arg1) {
    if (func_80137070(arg0 + 0x144) != 0) {
        if ((M2C_FIELD(arg0, f32 *, 0x98) < 400.0f) && (func_800B7164(arg0, 0x4000) == 0)) {
            M2C_FIELD(arg0, s16 *, 0x190) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
            func_808D075C(arg0);
            return;
        }
        if ((M2C_FIELD(arg0, f32 *, 0x98) < 280.0f) && (func_800B7164(arg0, 0x2000) != 0)) {
            func_808D0A50(arg0, arg1);
            return;
        }
        func_808D02E4(arg0);
    }
}
