// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK PadMgr_RumbleSet(M2C_UNK *);                   /* extern */
M2C_UNK func_80183D80(M2C_UNK *);                   /* extern */
extern M2C_UNK D_801EE250;

void Rumble_Update(s32 arg0) {
    func_80183D80(&D_801EE250);
    PadMgr_RumbleSet(&D_801EE250);
}
