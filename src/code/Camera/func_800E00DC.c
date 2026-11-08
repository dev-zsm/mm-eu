// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

f32 Camera_GetWaterYPos(struct Camera *camera) {
    if (M2C_FIELD(camera, s16 *, 0x14C) & 0x100) {
        return M2C_FIELD(camera, f32 *, 0x114);
    }
    return -32000.0f;
}
