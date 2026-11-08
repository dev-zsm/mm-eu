// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Camera_SetCameraData(struct Camera *camera, s16 setDataFlags, void *data0, void *data1, s16 data2, s16 data3) {
    if (setDataFlags & 1) {
        M2C_FIELD(camera, s32 *, 0x124) = data0;
    }
    if (setDataFlags & 2) {
        M2C_FIELD(camera, s32 *, 0x128) = data1;
    }
    if (setDataFlags & 4) {
        M2C_FIELD(camera, s16 *, 0x12C) = data2;
    }
    if (setDataFlags & 8) {
        M2C_FIELD(camera, s16 *, 0x12E) = data3;
    }
}
