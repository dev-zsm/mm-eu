// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern s32 D_801C9E40;

s32 PadMgr_ControllerHasRumblePak(s32 arg0) {
    return M2C_FIELD((D_801C9E40 + arg0), u8 *, 0x2CD) == 1;
}
