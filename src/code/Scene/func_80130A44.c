// FLAGS: -O1 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Entrance_GetTransitionFlags(u16);                             /* extern */

void Scene_SetExitFade(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x1887F) = (s8) (Entrance_GetTransitionFlags(M2C_FIELD(arg0, u16 *, 0x1887A)) & 0x7F);
}
