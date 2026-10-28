// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800C60A4(s32, s32, s32);               /* extern */
s32 func_800CAD00(u8 *);                          /* extern */
M2C_UNK func_809FE640(u8 *, s32);                 /* extern */
extern M2C_UNK D_809FE8D8;

void func_80000574(u8 *arg0, s32 arg1) {
    if (func_800CAD00(arg0) == 0) {
        func_809FE640(arg0, M2C_FIELD(arg0, s32 *, 0x168));
        func_800C60A4(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144));
        M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_809FE8D8;
    }
}
