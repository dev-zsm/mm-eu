// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_8012C648(s32);                             /* extern */

void Gfx_SetupDL26_Opa(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x2B0) = func_8012C648(M2C_FIELD(arg0, s32 *, 0x2B0));
}
