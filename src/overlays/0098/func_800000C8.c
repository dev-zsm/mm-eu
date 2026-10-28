// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B5D20(s32, M2C_UNK);                /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800B877C(u8 *, s32);                     /* extern */
M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_808BC634(u8 *, s32);                 /* extern */

void func_800000C8(u8 *arg0, s32 arg1) {
    func_808BC634(arg0, arg1);
    if (!(M2C_FIELD(arg0, f32 *, 0x168) < 0.5f)) {
        if (func_800B877C(arg0, arg1) != 0) {
            func_800B5D20(arg1, 0x1F);
            func_800B6490(arg0);
            return;
        }
        func_800B87A0(arg0, arg1, 0xD, 0x41F00000, 80.0f);
    }
}
