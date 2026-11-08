// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0572.h"

extern M2C_UNK D_80BB90F8;

void ObjHgdoor_SetupHandleCutscene(ObjHgdoor *this) {
    M2C_FIELD(this, s16 *, 0x166) = 0x63;
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80BB90F8;
}
