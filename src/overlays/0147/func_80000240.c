// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80000240(u8 *arg0) {
    s16 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x1C);
    if (temp_v1 & 0x8000) {
        return (temp_v1 & 0xFF) + 0x200;
    }
    return -0x200 - (temp_v1 & 0xFF);
}
