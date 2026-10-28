// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern s32 D_80BCAB20;

void func_800005F4(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x1C) >= 0x64) {
        D_80BCAB20 -= 1;
    }
}
