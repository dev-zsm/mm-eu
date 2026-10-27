// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s16 Play_GetActiveCamId(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x810);
}
