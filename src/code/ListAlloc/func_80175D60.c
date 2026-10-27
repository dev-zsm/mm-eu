// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK ListAlloc_Free(s32 *, s32);                  /* extern */

void ListAlloc_FreeAll(s32 *arg0) {
    if (*arg0 != 0) {
        do {
            ListAlloc_Free(arg0, *arg0 + 8);
        } while (*arg0 != 0);
    }
}
