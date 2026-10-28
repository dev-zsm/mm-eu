// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                            /* extern */
extern M2C_UNK D_801E6EF0;

void func_80000A8C(void) {
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF06) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF06) | 4);
    func_800B6490();
}
