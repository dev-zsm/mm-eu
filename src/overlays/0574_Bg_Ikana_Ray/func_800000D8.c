// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0574.h"

extern M2C_UNK D_80BBA25C;

void BgIkanaRay_SetDeactivated(BgIkanaRay *this) {
    M2C_FIELD(this, s32 *, 0x13C) = 0;
    M2C_FIELD(this, s32 *, 4) = (s32) (M2C_FIELD(this, s32 *, 4) | 0x10);
    M2C_FIELD(this, M2C_UNK **, 0x194) = &D_80BBA25C;
}
