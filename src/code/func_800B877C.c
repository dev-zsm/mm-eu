// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Actor_HasParent(void *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x120) != 0) {
        return 1;
    }
    return 0;
}
