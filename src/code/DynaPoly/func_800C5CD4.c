// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 THA_AllocTailAlign(s32, s32, M2C_UNK, s32);          /* extern */

void DynaPoly_AllocVtxList(s32 arg0, s32 *arg1, s32 arg2) {
    *arg1 = THA_AllocTailAlign(arg0 + 0x74, arg2 * 6, -2, arg0);
}
