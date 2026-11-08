// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0497.h"

extern M2C_UNK D_80B4A5C4;

void ObjKendoKanban_SetupDoNothing(ObjKendoKanban *this) {
    M2C_FIELD(this, M2C_UNK **, 0x268) = &D_80B4A5C4;
}
