// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern void *D_801EE3E0;

void CutsceneCamera_Reset(void) {
    M2C_FIELD(D_801EE3E0, s16 *, 6) = 0;
}
