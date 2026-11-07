// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

extern M2C_UNK D_8092091C;

void ObjSwitch_EyeSwitchClosedInit(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_8092091C;
    M2C_FIELD(arg0, s8 *, 0x164) = 3;
}
