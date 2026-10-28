// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80003284(u8 *arg0, M2C_UNK arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x120);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x124) = 0;
    }
}
