// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK PlayerAnimation_SetUpdateFunction();                            /* extern */

void PlayerAnimation_EndLoop(void *arg0) {
    M2C_FIELD(arg0, s8 *, 1) = 2;
    PlayerAnimation_SetUpdateFunction();
}
