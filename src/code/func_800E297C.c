// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 CollisionCheck_IsElementNotAC(void *arg0) {
    if (!(M2C_FIELD(arg0, u8 *, 0x16) & 1)) {
        return 1;
    }
    return 0;
}
