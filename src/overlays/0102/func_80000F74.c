// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808C23D0();                            /* extern */

void func_80000F74(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x250) = (s16) (M2C_FIELD(arg0, s16 *, 0x250) - 1);
    if (M2C_FIELD(arg0, s16 *, 0x250) == 0) {
        func_808C23D0();
    }
}
