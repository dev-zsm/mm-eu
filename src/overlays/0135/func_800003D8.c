// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_808FF7B4;

void func_800003D8(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x312) = func_800FF250(5, 0x23, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x308) = &D_808FF7B4;
    M2C_FIELD(arg0, u16 *, 0x30C) = (u16) (M2C_FIELD(arg0, u16 *, 0x30C) | 0x100);
}
