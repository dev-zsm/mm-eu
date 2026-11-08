// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0368.h"

extern M2C_UNK D_80A67C18;

void ObjMine_Path_SetupStationary(ObjMine *this) {
    M2C_FIELD(this, M2C_UNK **, 0x1A4) = &D_80A67C18;
}
