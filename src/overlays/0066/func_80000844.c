// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(u8 *, s16, M2C_UNK);        /* extern */
s32 func_80137070(s32);                             /* extern */
M2C_UNK func_808747D8(u8 *);                      /* extern */

void func_80000844(u8 *arg0, M2C_UNK arg1) {
    if (func_80137070(arg0 + 0x144) != 0) {
        func_808747D8(arg0);
    }
    func_800FEC70(arg0 + 0xBE, (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000), 0xB6);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
}
