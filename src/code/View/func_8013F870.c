// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 View_ClearDistortion(void *arg0) {
    M2C_FIELD(arg0, f32 *, 0x128) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x12C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x130) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x134) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x138) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x13C) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x140) = 1.0f;
    return 1;
}
