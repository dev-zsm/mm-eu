// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Gfx_SetupDL25_Opa(s32, s32 *);                  /* extern */

void func_8012C718(s32 *arg0) {
    Gfx_SetupDL25_Opa(*arg0, arg0);
}
