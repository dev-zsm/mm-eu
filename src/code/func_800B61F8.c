// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Actor_UpdatePlayerImpact(void *arg0) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x1E95);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8 *, 0x1E95) = (u8) (temp_v0 - 1);
    }
}
