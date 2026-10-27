// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

f32 Camera_GetWaterYPos(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x14C) & 0x100) {
        return M2C_FIELD(arg0, f32 *, 0x114);
    }
    return -32000.0f;
}
