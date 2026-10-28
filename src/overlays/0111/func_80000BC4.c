// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_808D5324(u8 *);                      /* extern */
M2C_UNK func_808D56D8(u8 *);                      /* extern */

void func_80000BC4(u8 *arg0, u8 *arg1) {
    func_80137070(arg0 + 0x144);
    if (!(M2C_FIELD(arg1, s32 *, 0x18840) & 0x5F)) {
        func_800B8C4C(arg0, 0x38E4);
    }
    M2C_FIELD(arg0, s16 *, 0x3E4) = (s16) (M2C_FIELD(arg0, s16 *, 0x3E4) + 1);
    if (M2C_FIELD(arg0, s16 *, 0x3E4) >= 0xB) {
        if ((M2C_FIELD(arg0, s16 *, 0x1C) != 2) && (M2C_FIELD(arg0, u8 *, 0x3EC) == 0)) {
            func_808D5324(arg0);
        } else {
            func_808D56D8(arg0);
        }
        M2C_FIELD(arg0, s16 *, 0x3E4) = 0;
    }
}
