// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0575.h"

extern M2C_UNK D_80BBAA2C;

void BgIkanaShutter_SetupDoNothing(BgIkanaShutter *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80BBAA2C;
    M2C_FIELD(this, f32 *, 0x28) = (f32) (M2C_FIELD(this, f32 *, 0xC) + -220.0f);
}
