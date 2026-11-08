// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0153.h"

extern M2C_UNK D_8091CCB4;

void func_800014C0(ObjBean *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_8091CCB4;
}
