// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808AD520();                            /* extern */

void func_80001488(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x1DC) == 0x11) {
        M2C_FIELD(arg0, u8 *, 0x268) = (u8) (M2C_FIELD(arg0, u8 *, 0x268) & 0xFFFE);
    }
    if (M2C_FIELD(arg0, s16 *, 0x1DC) == 0) {
        func_808AD520();
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x1DC) = (s16) (M2C_FIELD(arg0, s16 *, 0x1DC) - 1);
}
