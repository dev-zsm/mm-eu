// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80AAE3E4();                            /* extern */

void func_800005BC(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x174) = (s16) (M2C_FIELD(arg0, s16 *, 0x174) - 1);
    if (M2C_FIELD(arg0, s16 *, 0x174) <= 0) {
        func_80AAE3E4();
    }
}
