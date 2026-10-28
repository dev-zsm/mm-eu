// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800002C4(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x98) < 600.0f) {
        return 1;
    }
    return 0;
}
