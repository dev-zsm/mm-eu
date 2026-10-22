// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 MsgEvent_UnsetAutotalk(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xFFFEFFFF);
    return 0;
}
