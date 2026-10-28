// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BCE5AC;

void func_800002E0(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x270) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x254) = &D_80BCE5AC;
}
