// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0461.h"

extern M2C_UNK D_80AF96F0;

void func_80000828(ObjHakaisi *this) {
    M2C_FIELD(this, s16 *, 0x19A) = 0;
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80AF96F0;
}
