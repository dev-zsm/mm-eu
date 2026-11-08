// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

extern M2C_UNK D_80920D40;

void ObjSwitch_CrystalSwitchTurnOffInit(ObjSwitch *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80920D40;
}
