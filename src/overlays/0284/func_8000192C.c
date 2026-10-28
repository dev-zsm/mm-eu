// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809B6BA4;

void func_8000192C(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x464) = &D_809B6BA4;
}
