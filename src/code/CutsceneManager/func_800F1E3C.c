// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK CutsceneManager_GetCutsceneEntryImpl(s16);                         /* extern */

struct CutsceneEntry * CutsceneManager_GetCutsceneEntry(s16 csId) {
    CutsceneManager_GetCutsceneEntryImpl(csId);
}
