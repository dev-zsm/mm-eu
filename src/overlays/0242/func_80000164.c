// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A26A4(s32, s8, u8 *);             /* extern */
extern M2C_UNK D_801E6EF0;

void func_80000164(u8 *arg0, M2C_UNK arg1) {
    if ((M2C_FIELD(&D_801E6EF0, u8 *, 0x1010) & 2) || (M2C_FIELD(&D_801E6EF0, u8 *, 0x100F) & 0x20)) {
        func_801A26A4(arg0 + 0xEC, M2C_FIELD(arg0, s8 *, 0x1D), arg0);
    }
}
