// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
extern u8 *D_801EB7E0;

void func_8002CE78(u8 *arg0, u8 *arg1, M2C_UNK arg2) {
    if ((M2C_FIELD(arg1, u8 *, 0x14B) != 4) && (M2C_FIELD(arg0, u8 *, 0x186E3) == 5)) {
        M2C_FIELD(D_801EB7E0, s16 *, 0x454) = 0x2D;
        M2C_FIELD(D_801EB7E0, s16 *, 0x456) = 0xFF;
        M2C_FIELD(D_801EB7E0, s16 *, 0x458) = 0xFF;
        M2C_FIELD(D_801EB7E0, s16 *, 0x45A) = 0xFF;
        M2C_FIELD(D_801EB7E0, s16 *, 0x45C) = 0;
        func_8019FF78(0x4834);
    }
}
