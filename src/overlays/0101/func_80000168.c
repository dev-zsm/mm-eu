// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000168(u8 *arg0) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x1F8);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 4) = (s32) (M2C_FIELD(temp_v0, s32 *, 4) & ~0x2000);
        M2C_FIELD(arg0, u8 **, 0x1F8) = NULL;
    }
}
