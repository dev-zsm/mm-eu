// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern s16 D_801C1B84;

void Quake_Remove(void *arg0) {
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s16 *, 0x1E) = -1;
    D_801C1B84 -= 1;
}
