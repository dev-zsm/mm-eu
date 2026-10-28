// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800002B4(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x116) = 0xC01;
    return 0;
}
