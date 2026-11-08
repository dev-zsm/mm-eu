// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

extern M2C_UNK D_809208B0;

void ObjSwitch_EyeSwitchClosingInit(ObjSwitch *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_809208B0;
}
