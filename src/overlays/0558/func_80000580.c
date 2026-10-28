// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BA9A08;

void func_80000580(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s8 *, 0x15E) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x164) = &D_80BA9A08;
    }
}
