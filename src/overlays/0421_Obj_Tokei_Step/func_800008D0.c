// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0421.h"

extern M2C_UNK D_80ABB1D4;

void ObjTokeiStep_SetupDoNothingOpen(ObjTokeiStep *this) {
    M2C_FIELD(this, s32 *, 4) = (s32) (M2C_FIELD(this, s32 *, 4) & ~0x10);
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80ABB1D4;
}
