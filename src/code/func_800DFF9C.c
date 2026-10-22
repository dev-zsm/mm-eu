// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Camera_SetCameraData(void *arg0, s16 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5) {
    if (arg1 & 1) {
        M2C_FIELD(arg0, s32 *, 0x124) = arg2;
    }
    if (arg1 & 2) {
        M2C_FIELD(arg0, s32 *, 0x128) = arg3;
    }
    if (arg1 & 4) {
        M2C_FIELD(arg0, s16 *, 0x12C) = arg4;
    }
    if (arg1 & 8) {
        M2C_FIELD(arg0, s16 *, 0x12E) = arg5;
    }
}
