// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0441.h"

extern M2C_UNK D_80AD880C;

void ObjLightblock_SetupWait(ObjLightblock *this) {
    M2C_FIELD(this, M2C_UNK **, 0x1A8) = &D_80AD880C;
}
