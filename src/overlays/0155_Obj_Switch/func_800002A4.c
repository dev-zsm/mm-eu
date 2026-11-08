// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

void ObjSwitch_CrystalUpdateTimer(ObjSwitch *this) {
    M2C_FIELD(this, s32 *, 0x168) = (s32) (M2C_FIELD(this, s32 *, 0x168) + 1);
}
