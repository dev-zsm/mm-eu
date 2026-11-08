// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0305.h"

void func_80001D34(ObjIceblock *this) {
    M2C_FIELD(this, s16 *, 0x2A2) = 0;
}
