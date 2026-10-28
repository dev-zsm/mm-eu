// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */
M2C_UNK func_80A5D47C(u8 *, s32);                 /* extern */

void func_80002108(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x290) == 0) {
        M2C_FIELD(arg0, s16 *, 0x28E) = func_800FF250(0x1E, 0x1E, arg0);
        M2C_FIELD(arg0, s8 *, 0x371) = 0;
        M2C_FIELD(arg0, u8 *, 0xF05) = (u8) (M2C_FIELD(arg0, u8 *, 0xF05) | 4);
        func_80A5D47C(arg0, arg1);
    }
}
