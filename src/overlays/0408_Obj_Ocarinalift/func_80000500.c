// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0408.h"

extern M2C_UNK D_80AAE704;

void func_80000500(ObjOcarinalift *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80AAE704;
}
