// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0368.h"

extern M2C_UNK D_80A67F50;

void ObjMine_Air_SetupChained(ObjMine *this) {
    M2C_FIELD(this, M2C_UNK **, 0x1A4) = &D_80A67F50;
}
