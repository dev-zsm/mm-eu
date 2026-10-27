// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 View_SetDistortionOrientation(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    M2C_FIELD(arg0, f32 *, 0x128) = arg1;
    M2C_FIELD(arg0, f32 *, 0x12C) = arg2;
    M2C_FIELD(arg0, f32 *, 0x130) = arg3;
    return 1;
}
