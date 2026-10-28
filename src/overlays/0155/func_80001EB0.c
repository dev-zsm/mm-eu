// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809213A8();                            /* extern */
M2C_UNK func_8092148C();                            /* extern */

void func_80001EB0(u8 *arg0) {
    if (((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 3) & 1) {
        func_8092148C();
        return;
    }
    func_809213A8();
}
