// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E2500(s32, s32, s32, u8 *);       /* extern */
s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_8090E91C(u8 *, s32);                 /* extern */

void func_800012C8(u8 *arg0, s32 arg1) {
    func_800E2500(arg1, arg1 + 0x18884, arg0 + 0x478, arg0);
    if (func_80137070(arg0 + 0x144) != 0) {
        M2C_FIELD(arg0, s16 *, 0x2F6) = (s16) (M2C_FIELD(arg0, s16 *, 0x2F6) - 1);
        if (M2C_FIELD(arg0, s16 *, 0x2F6) == 0) {
            func_8090E91C(arg0, arg1);
        }
    }
}
