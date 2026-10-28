// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(u8 *, s16, M2C_UNK);        /* extern */
s32 func_80137C58(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_808E607C(u8 *);                      /* extern */
M2C_UNK func_808EA28C(u8 *);                      /* extern */

void func_80005BA4(u8 *arg0) {
    func_808E607C(arg0);
    func_800FEC70(arg0 + 0x2D0, M2C_FIELD(arg0, s16 *, 0x32), 0x800);
    if (func_80137C58(arg0 + 0x144, 0x41900000) != 0) {
        func_808EA28C(arg0);
    }
}
