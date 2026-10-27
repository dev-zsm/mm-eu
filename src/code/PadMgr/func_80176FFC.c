// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK PadMgr_RumblePause();                            /* extern */
extern void *D_801C9E40;

void PadMgr_HandlePreNMI(void) {
    M2C_FIELD(D_801C9E40, s8 *, 0x47E) = 1;
    PadMgr_RumblePause();
}
