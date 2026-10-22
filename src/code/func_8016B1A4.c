// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_8016B1A4(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x828) != 0;
}
