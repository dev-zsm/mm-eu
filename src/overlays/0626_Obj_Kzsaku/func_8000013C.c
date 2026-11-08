// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0626.h"

extern M2C_UNK D_80BED970;

void func_8000013C(ObjKzsaku *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80BED970;
}
