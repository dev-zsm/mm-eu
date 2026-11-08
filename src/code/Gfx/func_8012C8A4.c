// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 func_8012C87C(s32);                             /* extern */

void Gfx_SetupDL34_Opa(struct GraphicsContext *gfxCtx) {
    M2C_FIELD(gfxCtx, s32 *, 0x2B0) = func_8012C87C(M2C_FIELD(gfxCtx, s32 *, 0x2B0));
}
