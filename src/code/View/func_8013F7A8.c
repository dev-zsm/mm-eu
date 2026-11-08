// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 View_SetDistortionOrientation(struct View *view, f32 rotX, f32 rotY, f32 rotZ) {
    M2C_FIELD(view, f32 *, 0x128) = rotX;
    M2C_FIELD(view, f32 *, 0x12C) = rotY;
    M2C_FIELD(view, f32 *, 0x130) = rotZ;
    return 1;
}
