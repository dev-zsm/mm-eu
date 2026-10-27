// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_800CAD48(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x158) & 8) {
        return 1;
    }
    return 0;
}
