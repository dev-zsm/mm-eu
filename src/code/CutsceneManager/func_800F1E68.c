// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void *CutsceneManager_GetCutsceneEntryImpl(s16);                           /* extern */

s16 CutsceneManager_GetAdditionalCsId(s16 csId) {
    if (csId < 0) {
        return -1;
    }
    return M2C_FIELD(CutsceneManager_GetCutsceneEntryImpl(csId), s16 *, 8);
}
