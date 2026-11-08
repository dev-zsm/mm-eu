// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 Camera_UnsetViewFlag(struct Camera *camera, s16 viewFlag) {
    M2C_FIELD(camera, s16 *, 0x15C) = (s16) (M2C_FIELD(camera, s16 *, 0x15C) & ~viewFlag);
    return 1;
}
