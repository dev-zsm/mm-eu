// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK Lights_New(s32, u8, u8, u8);             /* extern */

struct Lights * LightContext_NewLights(struct LightContext *lightCtx, struct GraphicsContext *gfxCtx) {
    Lights_New(gfxCtx, M2C_FIELD(lightCtx, u8 *, 4), M2C_FIELD(lightCtx, u8 *, 5), M2C_FIELD(lightCtx, u8 *, 6));
}
