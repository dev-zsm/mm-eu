// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0619.h"

extern M2C_UNK D_80BEB3E0;

void func_8000011C(ObjMoonStone *this) {
    M2C_FIELD(this, M2C_UNK **, 0x190) = &D_80BEB3E0;
}
