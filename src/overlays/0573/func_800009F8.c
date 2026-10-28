// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BB9ED4;

void func_800009F8(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x1AC) = 0x1E;
    M2C_FIELD(arg0, M2C_UNK **, 0x1A8) = &D_80BB9ED4;
}
