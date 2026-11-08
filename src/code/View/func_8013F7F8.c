// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 View_SetDistortionSpeed(struct View *view, f32 speed) {
    M2C_FIELD(view, f32 *, 0x140) = speed;
    return 1;
}
