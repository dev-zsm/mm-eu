// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void *CutsceneManager_GetCutsceneEntryImpl(s16);                           /* extern */

s16 CutsceneManager_GetAdditionalCsId(s16 arg0) {
    if (arg0 < 0) {
        return -1;
    }
    return M2C_FIELD(CutsceneManager_GetCutsceneEntryImpl(arg0), s16 *, 8);
}
