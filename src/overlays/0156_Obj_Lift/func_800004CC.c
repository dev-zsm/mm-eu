// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0156.h"

extern M2C_UNK D_809223A4;
extern M2C_UNK D_80922780;

void func_800004CC(ObjLift *this) {
    M2C_FIELD(this, s16 *, 0x166) = 0x14;
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_809223A4;
    M2C_FIELD(this, M2C_UNK **, 0x13C) = &D_80922780;
}
