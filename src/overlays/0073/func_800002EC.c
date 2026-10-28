// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800002EC(u8 *arg0) {
    if ((M2C_FIELD(arg0, s16 *, 0x1C) == -2) && (M2C_FIELD(arg0, u16 *, 0x90) & 0x20)) {
        return 1;
    }
    return 0;
}
