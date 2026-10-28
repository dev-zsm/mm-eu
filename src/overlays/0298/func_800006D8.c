// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809FF920;

void func_800006D8(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x234) = &D_809FF920;
    M2C_FIELD(arg0, s16 *, 0x33E) = 0;
}
