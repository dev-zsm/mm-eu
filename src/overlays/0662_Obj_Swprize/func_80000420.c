// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0662.h"

extern M2C_UNK D_80C0A534;

void ObjSwprize_SetupDoNothing(ObjSwprize *this) {
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_80C0A534;
}
