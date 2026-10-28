// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s32);                        /* extern */
s32 func_80BA8AA8(u8 *, s32, M2C_UNK);            /* extern */
M2C_UNK func_80BA8DD8(u8 *);                      /* extern */
extern M2C_UNK D_80BA90E4;
extern M2C_UNK D_80BA9294;

void func_80000A4C(u8 *arg0, s32 arg1) {
    if (func_80BA8AA8(arg0, arg1, 1) != 0) {
        if (func_800B5B20(arg1, (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xFE00) >> 9) != 0) {
            func_80BA8DD8(arg0);
            M2C_FIELD(arg0, M2C_UNK **, 0x16C) = &D_80BA90E4;
        }
    } else {
        M2C_FIELD(arg0, M2C_UNK **, 0x16C) = &D_80BA9294;
    }
}
