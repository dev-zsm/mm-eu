// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0178.h"

extern M2C_UNK D_80945EEC;

void ObjMure2_SetupWaitForPlayerInRange(ObjMure2 *this) {
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_80945EEC;
}
