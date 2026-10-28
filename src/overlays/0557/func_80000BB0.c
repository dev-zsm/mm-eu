// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, s32, M2C_UNK);           /* extern */
extern M2C_UNK D_80BA9294;

void func_80000BB0(u8 *arg0, M2C_UNK arg1) {
    if (func_800B5B20(arg1, (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xFE00) >> 9, arg1) == 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x16C) = &D_80BA9294;
    }
}
