// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80000260(u8 *arg0, M2C_UNK arg1) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x1FD);
    if (temp_v0 & 2) {
        M2C_FIELD(arg0, u8 *, 0x1FD) = (u8) (temp_v0 & 0xFFFD);
    }
    return 0;
}
