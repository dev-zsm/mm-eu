// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80954B40;

void func_80000808(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x196) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x148) = &D_80954B40;
}
