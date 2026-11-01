// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK PadMgr_GetInput(s32, M2C_UNK, s32);           /* extern */

void GameState_GetInput(s32 arg0) {
    PadMgr_GetInput(arg0 + 0x14, 1, arg0);
}
