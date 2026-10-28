// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808B97EC();                            /* extern */

void func_80001A48(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1CE) = (s16) (M2C_FIELD(arg0, s16 *, 0x1CE) - 1);
    if (M2C_FIELD(arg0, s16 *, 0x1CE) <= 0) {
        func_808B97EC();
    }
}
