// FLAGS: -O1 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Entrance_GetTransitionFlags(u16);                             /* extern */

void Scene_SetExitFade(struct PlayState *play) {
    M2C_FIELD(play, s8 *, 0x1887F) = (s8) (Entrance_GetTransitionFlags(M2C_FIELD(play, u16 *, 0x1887A)) & 0x7F);
}
