// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void View_GetPerspective(struct View *view, f32 *fovy, f32 *zNear, f32 *zFar) {
    *fovy = M2C_FIELD(view, f32 *, 0x18);
    *zNear = M2C_FIELD(view, f32 *, 0x1C);
    *zFar = M2C_FIELD(view, f32 *, 0x20);
}
