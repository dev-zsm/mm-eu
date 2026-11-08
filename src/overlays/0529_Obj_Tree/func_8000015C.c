// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0529.h"

extern M2C_UNK D_80B7EFC0;

void ObjTree_SetupDoNothing(ObjTree *this) {
    M2C_FIELD(this, M2C_UNK **, 0x1A8) = &D_80B7EFC0;
}
