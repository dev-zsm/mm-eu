// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_80100304(s32);                             /* extern */

void Scene_CommandCutsceneScriptList(void *arg0, void *arg1) {
    M2C_FIELD(arg0, u8 *, 0x1F24) = (u8) M2C_FIELD(arg1, u8 *, 1);
    M2C_FIELD(arg0, s32 *, 0x1F74) = func_80100304(M2C_FIELD(arg1, s32 *, 4));
}
