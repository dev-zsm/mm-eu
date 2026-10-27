// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Audio_PlaySfx_MessageCancel();                            /* extern */

s32 MsgEvent_PlayCancel(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    Audio_PlaySfx_MessageCancel();
    return 0;
}
