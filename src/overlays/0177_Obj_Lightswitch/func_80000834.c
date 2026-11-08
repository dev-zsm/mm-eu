// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0177.h"

extern M2C_UNK D_80944F30;

void ObjLightSwitch_SetupFade(ObjLightswitch *this) {
    M2C_FIELD(this, s16 *, 0x1AE) = 0x3FC0;
    M2C_FIELD(this, M2C_UNK **, 0x1A4) = &D_80944F30;
}
