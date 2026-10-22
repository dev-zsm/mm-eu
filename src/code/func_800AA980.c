// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Gfx_SetupDL(s32, M2C_UNK);                    /* extern */

void EffectBlure_SetupSimple(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_FIELD(arg0, s32 *, 0x2C0) = Gfx_SetupDL(M2C_FIELD(arg0, s32 *, 0x2C0), 0x26);
}
