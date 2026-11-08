// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

M2C_UNK func_800F1D6C(s8, u8 *);                  /* extern */

void ObjSwitch_StopCutscene(ObjSwitch *this) {
    if (M2C_FIELD(this, s8 *, 0x172) != 0) {
        func_800F1D6C(M2C_FIELD(this, s8 *, 0x38), this);
        M2C_FIELD(this, s8 *, 0x172) = 0;
    }
}
