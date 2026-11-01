// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK PadMgr_LockPadData();                            /* extern */
M2C_UNK PadMgr_UnlockPadData();                            /* extern */
M2C_UNK PadMgr_GetInputNoLock(s32, s32);                    /* extern */

void PadMgr_GetInput2(s32 arg0, s32 arg1) {
    PadMgr_LockPadData();
    PadMgr_GetInputNoLock(arg0, arg1);
    PadMgr_UnlockPadData();
}
