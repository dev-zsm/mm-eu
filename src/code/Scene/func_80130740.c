// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_80100304(s32);                             /* extern */

void Scene_CommandExitList(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s32 *, 0x18860) = func_80100304(M2C_FIELD(arg1, s32 *, 4));
}
