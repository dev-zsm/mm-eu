// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B6807C;

void func_80000F94(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x178) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x168) = &D_80B6807C;
}
