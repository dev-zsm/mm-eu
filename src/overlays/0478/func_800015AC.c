// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 D_801E7EFF;
extern M2C_UNK D_80B177B8;
extern M2C_UNK D_80B185F0;

void func_800015AC(u8 *arg0, M2C_UNK arg1) {
    if (D_801E7EFF & 8) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1F8) = &D_80B177B8;
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80B185F0;
    }
}
