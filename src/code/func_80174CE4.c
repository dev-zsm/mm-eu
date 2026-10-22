// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK THA_GetRemaining(s32, s32);                    /* extern */

void GameState_GetArenaSize(s32 arg0) {
    THA_GetRemaining(arg0 + 0x74, arg0);
}
