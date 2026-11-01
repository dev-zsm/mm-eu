// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK CutsceneManager_Init(s32, s32, u8);                /* extern */
s32 func_80100304(s32);                             /* extern */

void Scene_CommandCutsceneList(s32 arg0, void *arg1) {
    CutsceneManager_Init(arg0, func_80100304(M2C_FIELD(arg1, s32 *, 4)), M2C_FIELD(arg1, u8 *, 1));
}
