// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 MsgEvent_Pause(s32 arg0, void *arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_FIELD(arg1, s8 *, 0x1682E) = 0x44;
    return 0;
}
