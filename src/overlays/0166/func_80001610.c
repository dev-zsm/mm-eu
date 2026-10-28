// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                            /* extern */
M2C_UNK func_8092DD78();                            /* extern */
M2C_UNK func_8092E0E8();                            /* extern */

void func_80001610(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2E56);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x2E56) = (s16) (temp_v0 - 1);
    }
    if (M2C_FIELD(arg0, s16 *, 0x1C) < 0) {
        func_8092DD78();
        return;
    }
    if (M2C_FIELD(arg0, s16 *, 0x2E56) != 0) {
        func_8092E0E8();
        return;
    }
    func_800B6490();
}
