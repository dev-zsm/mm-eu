// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(u8 *, s16, M2C_UNK);        /* extern */
s32 func_80137070(s32);                             /* extern */
M2C_UNK func_80893290(u8 *);                      /* extern */
M2C_UNK func_808937AC(u8 *, s32);                 /* extern */

void func_80000834(u8 *arg0, s32 arg1) {
    if (func_80137070(arg0 + 0x144) != 0) {
        func_808937AC(arg0, arg1);
        return;
    }
    func_80893290(arg0);
    func_800FEC70(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 0x3E8);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
}
