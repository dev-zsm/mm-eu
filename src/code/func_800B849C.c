// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Actor_OcarinaInteractionAccepted(void *arg0, M2C_UNK arg1) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_v1 & 0x20000000) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (temp_v1 & 0xDFFFFFFF);
        return 1;
    }
    return 0;
}
