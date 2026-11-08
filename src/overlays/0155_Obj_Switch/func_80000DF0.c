// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

extern M2C_UNK D_809204D4;

void ObjSwitch_FloorSwitchDownInit(ObjSwitch *this) {
    M2C_FIELD(this, s16 *, 0x160) = 6;
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_809204D4;
    M2C_FIELD(this, f32 *, 0x5C) = (f32) M2C_FIELD(this, f32 *, 0x254);
}
