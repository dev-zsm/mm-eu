// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 MapDisp_IsDataRotated(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0xA4) == 0x4A) {
        return 1;
    }
    return 0;
}
