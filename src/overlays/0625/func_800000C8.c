// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BED5DC;

void func_800000C8(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x190) = &D_80BED5DC;
}
