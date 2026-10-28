// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809430B0;

void func_80000ECC(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x190) = &D_809430B0;
}
