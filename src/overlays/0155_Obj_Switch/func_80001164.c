// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

extern M2C_UNK D_8092083C;

void ObjSwitch_EyeSwitchOpenInit(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_8092083C;
    M2C_FIELD(arg0, s8 *, 0x164) = 0;
}
