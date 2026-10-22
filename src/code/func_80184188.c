// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void FrameCtrl_SetProperties(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6) {
    M2C_FIELD(arg0, f32 *, 0) = arg1;
    if (arg2 < 1.0f) {
        M2C_FIELD(arg0, f32 *, 4) = arg3;
    } else {
        M2C_FIELD(arg0, f32 *, 4) = arg2;
    }
    M2C_FIELD(arg0, f32 *, 8) = arg3;
    M2C_FIELD(arg0, f32 *, 0xC) = arg5;
    M2C_FIELD(arg0, f32 *, 0x10) = arg4;
    M2C_FIELD(arg0, s32 *, 0x14) = arg6;
}
