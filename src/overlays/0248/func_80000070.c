// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_80984780(u8 *, s32);                     /* extern */
extern M2C_UNK D_80984B70;

void func_80000070(u8 *arg0, s32 arg1) {
    func_800FF8DC(arg0, &D_80984B70);
    if (func_80984780(arg0, arg1) == 0) {
        M2C_FIELD(arg0, s8 *, 0x144) = -1;
    }
    if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F) != 0) {
        func_800B6490(arg0);
    }
}
