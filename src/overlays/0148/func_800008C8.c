// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809138F8();                            /* extern */

void func_800008C8(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x220) <= 0) {
        func_809138F8();
    }
}
