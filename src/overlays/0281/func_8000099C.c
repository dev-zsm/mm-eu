// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809B1BC8();                            /* extern */

void func_8000099C(u8 *arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x2B0), u8 *, 0xB7) == 0) {
        func_809B1BC8();
    }
}
