// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */
M2C_UNK func_809936F0(u8 *, s32);                 /* extern */
extern s32 D_80995C80;

void func_80001A18(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x288) == 0) {
        M2C_FIELD(arg0, s16 *, 0x286) = func_800FF250(0x1E, 0x1E, arg0);
        M2C_FIELD(arg0, s8 *, 0x370) = 0xA;
        M2C_FIELD(arg0, u8 *, 0x36D) = (u8) (M2C_FIELD(arg0, u8 *, 0x36D) | 4);
        M2C_FIELD(arg0, s8 *, 0x34E) = 0;
        D_80995C80 = 0;
        M2C_FIELD(arg0, s16 *, 0x28E) = 0;
        func_809936F0(arg0, arg1);
    }
}
