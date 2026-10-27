// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK PadMgr_UnsetRumbleRetraceCallback(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK RumbleManager_Destroy(M2C_UNK *);                   /* extern */
extern M2C_UNK D_801EE250;
extern M2C_UNK Rumble_Update;

void Rumble_Destroy(void) {
    PadMgr_UnsetRumbleRetraceCallback(&Rumble_Update, 0);
    RumbleManager_Destroy(&D_801EE250);
}
