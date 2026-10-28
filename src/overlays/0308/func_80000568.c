// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A10EDC();                            /* extern */

void func_80000568(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1DA);
    if (temp_v0 >= 0x15) {
        func_80A10EDC();
        M2C_FIELD(arg0, s16 *, 0x1DA) = 0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x1DA) = (s16) (temp_v0 + 1);
}
