// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B485DC();                            /* extern */

void func_80002274(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 4) {
        func_80B485DC();
    }
}
