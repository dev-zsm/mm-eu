// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800004FC(u8 *arg0, M2C_UNK arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x4A4);
    M2C_FIELD(arg0, s32 *, 0x4AC) = (s32) (M2C_FIELD(arg0, s32 *, 0x4AC) | 0x10);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x4AC) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x4AC) | 0x10);
    }
}
