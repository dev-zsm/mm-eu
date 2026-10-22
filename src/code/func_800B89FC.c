// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Actor_HasRider(s32 arg0, void *arg1) {
    if (M2C_FIELD(arg1, s32 *, 0x124) != 0) {
        return 1;
    }
    return 0;
}
