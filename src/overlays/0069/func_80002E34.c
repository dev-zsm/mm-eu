// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8087DCD4();                            /* extern */

void func_80002E34(u8 *arg0) {
    s32 temp_v0;

    func_8087DCD4();
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1E8);
    if (!(temp_v0 & 0x100) && !(temp_v0 & 0x200)) {
        M2C_FIELD(arg0, s32 *, 0x1E8) = (s32) (temp_v0 | 0x200);
        M2C_FIELD(arg0, s16 *, 0x37C) = 8;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x37C) = 0;
}
