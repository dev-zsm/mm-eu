// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0303.h"

void func_80000E18(ObjSkateblock *this) {
    M2C_FIELD(this, s16 *, 0x17C) = 0;
}
