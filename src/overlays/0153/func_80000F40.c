// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK D_8091C790;

void func_80000F40(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x1E8) = &D_8091C790;
    M2C_FIELD(arg0, s16 *, 0x1EC) = func_800FF250(0xC, 0x28);
    M2C_FIELD(arg0, s16 *, 0x1F0) = func_800FF250(0xC8, 0x190);
    M2C_FIELD(arg0, s16 *, 0x1F2) = 0x14;
    M2C_FIELD(arg0, s16 *, 0x1F6) = func_800FF250(0x64, 0x320);
    M2C_FIELD(arg0, s16 *, 0x1F8) = 0x14;
}
