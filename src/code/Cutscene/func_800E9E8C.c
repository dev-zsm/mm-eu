// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Cutscene_StopManual(struct PlayState *play, struct CutsceneContext *csCtx) {
    if (M2C_FIELD(csCtx, u8 *, 8) != 4) {
        M2C_FIELD(csCtx, u8 *, 8) = 3U;
    }
}
