// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s16 Camera_SetStateFlag(struct Camera *camera, s16 flags) {
    M2C_FIELD(camera, s16 *, 0x14C) = (s16) (M2C_FIELD(camera, s16 *, 0x14C) | flags);
    return M2C_FIELD(camera, s16 *, 0x14C);
}
