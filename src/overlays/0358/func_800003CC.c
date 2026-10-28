// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern s32 D_80A506F4;

void func_800003CC(u8 *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x30C);
    if (temp_v0 & 0x100) {
        M2C_FIELD(arg0, s32 *, 0x30C) = (s32) (temp_v0 & ~0x100);
        D_80A506F4 -= 1;
    }
}
