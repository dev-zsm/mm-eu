// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Actor_ResetLensActors(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x1CAF) = 0;
    M2C_FIELD(arg0, s8 *, 0x1CAB) = 0;
}
