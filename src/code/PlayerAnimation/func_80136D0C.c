// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK PlayerAnimation_SetUpdateFunction();                            /* extern */

void PlayerAnimation_EndLoop(struct SkelAnime *skelAnime) {
    M2C_FIELD(skelAnime, s8 *, 1) = 2;
    PlayerAnimation_SetUpdateFunction();
}
