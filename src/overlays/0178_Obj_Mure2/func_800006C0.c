// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0178.h"

extern M2C_UNK D_80945EB4;

void func_800006C0(ObjMure2 *this) {
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_80945EB4;
}
