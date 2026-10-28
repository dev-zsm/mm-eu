// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8000C5F0(u8 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x370);
    if (temp_v0 == 5) {
        return -1;
    }
    if (temp_v0 == 4) {
        return 1;
    }
    return 0;
}
