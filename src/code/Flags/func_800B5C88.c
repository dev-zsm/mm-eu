// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Flags_GetClearTemp(void *arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 0x1E70) & (1 << arg1);
}
