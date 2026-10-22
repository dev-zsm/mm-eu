// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Actor_NoOcarinaInteraction(s32 arg0, void *arg1) {
    if (!(M2C_FIELD(M2C_FIELD(arg1, void **, 0x1CCC), s32 *, 4) & 0x20000000)) {
        return 1;
    }
    return 0;
}
