// FLAGS: -O2 -g3 -mips2
// STATUS: automatic draft, 10/20 instructions differ
#include "types.h"
#include "m2c_compat.h"

s32 func_801278E8(u8 **arg0, u8 *arg1, s32 arg2) {
    u8 *temp_a0;
    u8 *temp_v0;

    if ((M2C_FIELD(arg1, u8 *, 0x1FC) == 0) && (arg2 == M2C_FIELD(arg1, u8 *, 0x1FD))) {
        temp_v0 = *arg0;
        temp_a0 = M2C_FIELD(temp_v0, u8 **, 0x2B0);
        M2C_FIELD(temp_v0, u8 **, 0x2B0) = (u8 *) (temp_a0 + 8);
        M2C_FIELD(temp_a0, s32 *, 0) = 0xDB060028;
        M2C_FIELD(temp_a0, s32 *, 4) = (s32) M2C_FIELD(arg1, s32 *, 0x23C);
        return 1;
    }
    return 0;
}
