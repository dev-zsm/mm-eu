// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK ListAlloc_FreeAll(s32, s32);                    /* extern */

void PreRender_Destroy(s32 arg0) {
    ListAlloc_FreeAll(arg0 + 0x44, arg0);
}
