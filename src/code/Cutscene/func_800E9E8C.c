// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Cutscene_StopManual(s32 arg0, void *arg1) {
    if (M2C_FIELD(arg1, u8 *, 8) != 4) {
        M2C_FIELD(arg1, u8 *, 8) = 3U;
    }
}
