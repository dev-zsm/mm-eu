// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

f32 Camera_ScaledStepToCeilF(f32, f32, s32, s32);              /* extern */

void Camera_ScaledStepToCeilVec3f(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg1, f32 *, 0) = Camera_ScaledStepToCeilF(M2C_FIELD(arg0, f32 *, 0), M2C_FIELD(arg1, f32 *, 0), arg2, arg4);
    M2C_FIELD(arg1, f32 *, 4) = Camera_ScaledStepToCeilF(M2C_FIELD(arg0, f32 *, 4), M2C_FIELD(arg1, f32 *, 4), arg3, arg4);
    M2C_FIELD(arg1, f32 *, 8) = Camera_ScaledStepToCeilF(M2C_FIELD(arg0, f32 *, 8), M2C_FIELD(arg1, f32 *, 8), arg2, arg4);
}
