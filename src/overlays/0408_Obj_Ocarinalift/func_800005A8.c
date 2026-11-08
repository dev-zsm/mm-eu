// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0408.h"

extern M2C_UNK D_80AAE7AC;

void func_800005A8(ObjOcarinalift *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80AAE7AC;
}
