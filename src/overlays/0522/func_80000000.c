// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s8 func_800C9C4C(s32, s32, s32, s32, u8 *, M2C_UNK *, M2C_UNK *); /* extern */

void func_80000000(u8 *arg0, s32 arg1) {
    s32 pad;
    M2C_UNK sp30;
    M2C_UNK sp2C;

    M2C_FIELD(arg0, s8 *, 0x16B) = func_800C9C4C(arg1, arg1 + 0x830, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), arg0 + 0x16C, &sp30, &sp2C);
}
