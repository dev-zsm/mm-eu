// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A05440();                            /* extern */

void func_8000088C(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, u16 *, 0x90) & 2) {
        func_80A05440();
    }
}
