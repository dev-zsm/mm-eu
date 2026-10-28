// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_60021C8;
extern M2C_UNK D_80B301B4;

void func_80007A80(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_60021C8, 0xC0C00000);
    M2C_FIELD(arg0, s16 *, 0x2F0) = func_800FF250(0x32, 0x50);
    M2C_FIELD(arg0, M2C_UNK **, 0x2EC) = &D_80B301B4;
}
