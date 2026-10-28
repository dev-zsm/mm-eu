// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80917F04();                            /* extern */

void func_80000F48(u8 *arg0, M2C_UNK arg1) {
    if ((M2C_FIELD(arg0, s16 *, 0xBCA) == 0) || (M2C_FIELD(arg0, u8 *, 0xBCD) == 0)) {
        func_80917F04();
    }
}
