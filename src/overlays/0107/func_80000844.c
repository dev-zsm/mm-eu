// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFDD8(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_808CC1D8(u8 *);                      /* extern */

void func_80000844(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    func_800FFDD8(arg0 + 0x216, 0, 0xA, 0x5DC);
    func_80137070(arg0 + 0x144);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x214);
    if (temp_v0 == 0) {
        func_808CC1D8(arg0);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x214) = (s16) (temp_v0 - 1);
}
