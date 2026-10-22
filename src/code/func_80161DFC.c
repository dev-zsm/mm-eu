// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern void *D_801EE3D4;

s8 ShrinkWindow_Pillarbox_GetSize(void) {
    return M2C_FIELD(D_801EE3D4, s8 *, 3);
}
