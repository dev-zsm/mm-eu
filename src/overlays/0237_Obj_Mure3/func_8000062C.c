// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0237.h"

extern M2C_UNK D_809743C0;

void func_8000062C(ObjMure3 *this) {
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_809743C0;
}
