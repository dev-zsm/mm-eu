// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0497.h"

extern M2C_UNK D_80B4AA98;

void ObjKendoKanban_SetupSettled(ObjKendoKanban *this) {
    M2C_FIELD(this, M2C_UNK **, 0x268) = &D_80B4AA98;
}
