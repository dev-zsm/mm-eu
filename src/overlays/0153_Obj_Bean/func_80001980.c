// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0153.h"

extern M2C_UNK D_8091D17C;

void func_80001980(ObjBean *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_8091D17C;
    M2C_FIELD(this, s16 *, 0x1B2) = 0x49;
}
