// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK SkelAnime_SetUpdate();                            /* extern */

void Animation_EndLoop(void *arg0) {
    M2C_FIELD(arg0, s8 *, 1) = 2;
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) M2C_FIELD(arg0, f32 *, 0x14);
    SkelAnime_SetUpdate();
}
