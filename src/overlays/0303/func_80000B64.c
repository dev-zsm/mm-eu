// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000B64(u8 *arg0, u8 *arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    M2C_FIELD(temp_v0, s32 *, 0xA70) = (s32) (M2C_FIELD(temp_v0, s32 *, 0xA70) & ~0x10);
    M2C_FIELD(arg0, f32 *, 0x148) = 0.0f;
}
