// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000178C(s32 arg0, u8 *arg1, s16 arg2) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    M2C_FIELD(temp_v0, s16 *, 0x4A) = (s16) (M2C_FIELD(temp_v0, s16 *, 0x4A) + arg2);
}
