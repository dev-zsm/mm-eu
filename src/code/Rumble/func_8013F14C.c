// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK PadMgr_SetRumbleRetraceCallback(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_801840C0(M2C_UNK *);                   /* extern */
extern M2C_UNK D_801EE250;
extern M2C_UNK Rumble_Update;

void Rumble_Init(void) {
    func_801840C0(&D_801EE250);
    PadMgr_SetRumbleRetraceCallback(&Rumble_Update, 0);
}
