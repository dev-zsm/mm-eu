// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8091CEF8();                            /* extern */

void func_800016E0(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x1B2) <= 0) {
        M2C_FIELD(arg0, u8 *, 0x1FE) = (u8) (M2C_FIELD(arg0, u8 *, 0x1FE) | 4);
        func_8091CEF8();
    }
}
