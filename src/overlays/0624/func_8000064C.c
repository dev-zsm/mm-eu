// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000064C(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s32 *, 0x164) = -1;
}
