// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B2EFF0();                            /* extern */

void func_80006C34(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s8 *, 0x29C) != 0) {
        func_80B2EFF0();
    }
}
