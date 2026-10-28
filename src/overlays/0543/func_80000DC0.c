// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

u8 *func_8013D9F8(s32, s16, M2C_UNK);             /* extern */

void func_80000DC0(u8 *arg0, s32 arg1) {
    u8 *temp_v0;

    temp_v0 = func_8013D9F8(arg1, (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0x7E00) >> 9), 0x3F);
    M2C_FIELD(arg0, u8 **, 0x1EC) = temp_v0;
    M2C_FIELD(arg0, u8 **, 0x1F0) = func_8013D9F8(arg1, (s16) M2C_FIELD(temp_v0, u8 *, 1), 0x3F);
}
