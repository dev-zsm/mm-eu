// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK ZeldaArena_Free(s32);                         /* extern */

void SkelCurve_Destroy(s32 arg0, void *arg1) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg1, s32 *, 0x1C);
    if (temp_a0 != 0) {
        ZeldaArena_Free(temp_a0);
    }
}
