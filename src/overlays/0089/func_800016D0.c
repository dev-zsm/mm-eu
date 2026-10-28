// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                            /* extern */

void func_800016D0(u8 *arg0, M2C_UNK arg1) {
    u8 *temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0x1DE) == 0) {
        temp_v0 = M2C_FIELD(arg0, u8 **, 0x124);
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, s32 *, 0x120) = 0;
        }
        func_800B6490();
    }
}
