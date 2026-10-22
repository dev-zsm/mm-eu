// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Schedule_ReturnNone(s32 arg0, M2C_UNK arg1, void *arg2) {
    M2C_FIELD(arg2, s32 *, 0xC) = 0;
    return 1;
}
