// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Gfx_SetupDL(s32, M2C_UNK);                    /* extern */

void EffectBlure_SetupSmooth(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0x2C0) = Gfx_SetupDL(M2C_FIELD(arg1, s32 *, 0x2C0), 0x26);
}
