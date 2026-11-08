// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK PadMgr_LockPadData();                            /* extern */
M2C_UNK PadMgr_UnlockPadData();                            /* extern */
M2C_UNK PadMgr_GetInputNoLock(s32, s32);                    /* extern */

void PadMgr_GetInput(struct Input *inputs, s32 gameRequest) {
    PadMgr_LockPadData();
    PadMgr_GetInputNoLock(inputs, gameRequest);
    PadMgr_UnlockPadData();
}
