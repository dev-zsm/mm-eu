// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_8012C87C(s32);                             /* extern */

void Gfx_SetupDL34_Opa(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x2B0) = func_8012C87C(M2C_FIELD(arg0, s32 *, 0x2B0));
}
