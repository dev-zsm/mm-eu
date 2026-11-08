// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void View_SetScale(struct View *view, f32 scale) {
    M2C_FIELD(view, f32 *, 0x24) = scale;
    M2C_FIELD(view, s32 *, 0x160) = (s32) (M2C_FIELD(view, s32 *, 0x160) | 4);
}
