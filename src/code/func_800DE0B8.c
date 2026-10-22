// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s16 func_800DE0B8(void *arg0, s16 arg1) {
    if (arg0 == NULL) {
        return arg1;
    }
    M2C_FIELD(arg0, s16 *, 0x140) = arg1;
    return M2C_FIELD(arg0, s16 *, 0x140);
}
