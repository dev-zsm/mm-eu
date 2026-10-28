// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B2FA90;

void func_8000738C(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10000);
    M2C_FIELD(arg0, M2C_UNK **, 0x2EC) = &D_80B2FA90;
}
