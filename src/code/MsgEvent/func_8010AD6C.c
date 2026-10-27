// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 MsgEvent_Done(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 *arg4) {
    *arg4 = 1;
    return 1;
}
