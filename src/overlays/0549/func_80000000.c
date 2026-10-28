// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000000(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    if (!(M2C_FIELD(arg0, s16 *, 0x1C) & 0x100)) {
        M2C_FIELD(arg0, s8 *, 0x144) = 0;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x1C) = 0xC8;
    M2C_FIELD(arg0, s8 *, 0x144) = 1;
}
