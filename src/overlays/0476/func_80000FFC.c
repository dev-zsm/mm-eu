// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEC70(s32, s16, M2C_UNK);               /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80B116E8(u8 *, s32);                 /* extern */
M2C_UNK func_80B11890(u8 *);                      /* extern */
M2C_UNK func_80B11A44(u8 *);                      /* extern */

void func_80000FFC(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x144);
    if (func_800FEC70(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x192), 0x71C) != 0) {
        func_80B11890(arg0);
    }
    if (M2C_FIELD(arg0, f32 *, 0x98) < 200.0f) {
        func_80B11A44(arg0);
    }
    func_80B116E8(arg0, arg1);
}
