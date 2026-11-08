// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0105.h"

extern M2C_UNK D_808C749C;

void func_80002E38(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_808C749C;
}
