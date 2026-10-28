// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B2BC18;
extern s32 D_80B33670;

void func_80003510(u8 *arg0) {
    D_80B33670 = 2;
    M2C_FIELD(arg0, s16 *, 0x2F0) = 0xA0;
    M2C_FIELD(arg0, M2C_UNK **, 0x2EC) = &D_80B2BC18;
}
