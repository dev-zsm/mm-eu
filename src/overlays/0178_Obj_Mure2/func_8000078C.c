// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0178.h"

extern M2C_UNK D_80945F80;

void ObjMure2_SetupWaitForPlayerOutOfRange(ObjMure2 *this) {
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_80945F80;
}
