// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800DF888(s32, M2C_UNK);                /* extern */
s32 func_8016A844(u8 *, M2C_UNK);                 /* extern */
extern M2C_UNK D_801E6EF0;

void func_800003A8(u8 *arg0) {
    func_800DF888(func_8016A844(arg0, 0), 1);
    if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) & 0x20)) {
        M2C_FIELD(&D_801E6EF0, u8 *, 0x1010) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x1010) & 0xFD);
    }
    M2C_FIELD(arg0, s8 *, 0x1887C) = -1;
}
