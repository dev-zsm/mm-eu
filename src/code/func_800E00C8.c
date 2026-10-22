// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Camera_SetTargetActor(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xA8) = arg1;
    M2C_FIELD(arg0, s16 *, 0x15E) = 0x14;
}
