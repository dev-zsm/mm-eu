// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK D_8091C844;

void func_80000FF4(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x1E8) = &D_8091C844;
    M2C_FIELD(arg0, s16 *, 0x1EC) = func_800FF250(0x1E, 4);
    M2C_FIELD(arg0, s16 *, 0x1F0) = func_800FF250(0x7D0, 0x3E8);
    M2C_FIELD(arg0, s16 *, 0x1F2) = 0xC8;
    M2C_FIELD(arg0, s16 *, 0x1F6) = func_800FF250(0x36B0, 0x1770);
    M2C_FIELD(arg0, s16 *, 0x1F8) = 0xFA0;
}
