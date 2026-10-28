// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808C749C;

void func_80002E38(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808C749C;
}
