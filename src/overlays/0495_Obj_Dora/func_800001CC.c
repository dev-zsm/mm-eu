// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0495.h"

extern M2C_UNK D_80B459E0;

void ObjDora_SetupWait(ObjDora *this) {
    M2C_FIELD(this, M2C_UNK **, 0x38C) = &D_80B459E0;
}
