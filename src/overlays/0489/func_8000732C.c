// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B2FA20;

void func_8000732C(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x2EC) = &D_80B2FA20;
}
