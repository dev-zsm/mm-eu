// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK SkelAnime_SetUpdate();                            /* extern */

void Animation_EndLoop(struct SkelAnime *skelAnime) {
    M2C_FIELD(skelAnime, s8 *, 1) = 2;
    M2C_FIELD(skelAnime, f32 *, 0x10) = (f32) M2C_FIELD(skelAnime, f32 *, 0x14);
    SkelAnime_SetUpdate();
}
