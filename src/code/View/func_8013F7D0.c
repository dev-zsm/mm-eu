// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 View_SetDistortionScale(struct View *view, f32 scaleX, f32 scaleY, f32 scaleZ) {
    M2C_FIELD(view, f32 *, 0x134) = scaleX;
    M2C_FIELD(view, f32 *, 0x138) = scaleY;
    M2C_FIELD(view, f32 *, 0x13C) = scaleZ;
    return 1;
}
