// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A429F8;
extern M2C_UNK D_80A437A8;

void func_80002B10(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x190) = &D_80A429F8;
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A437A8;
    M2C_FIELD(arg0, s16 *, 0x1CA) = 0x50;
}
