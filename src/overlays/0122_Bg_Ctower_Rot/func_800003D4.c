// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0122.h"

M2C_UNK func_800F1944(s8, u8 *);                  /* extern */
s32 func_800F1984(s8, u8 *);                      /* extern */
M2C_UNK func_800F1A08(s8, u8 *);                  /* extern */
extern M2C_UNK D_808E19BC;

void BgCtowerRot_SetupDoorClose(BgCtowerRot *this, PlayState *play) {
    if (func_800F1984(M2C_FIELD(this, s8 *, 0x38), this) != 0) {
        if (M2C_FIELD(this, s16 *, 0x1C) == 1) {
            func_800F1A08(M2C_FIELD(this, s8 *, 0x38), this);
        }
        M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_808E19BC;
        return;
    }
    func_800F1944(M2C_FIELD(this, s8 *, 0x38), this);
}
