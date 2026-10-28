// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(s32);                         /* extern */
M2C_UNK func_800B6564(s32, M2C_UNK);                /* extern */
extern M2C_UNK D_801E6EF0;

void func_80000000(s32 arg0, M2C_UNK arg1) {
    if ((M2C_FIELD(&D_801E6EF0, s32 *, 0x10) != 1) || ((((s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5) == 3) && (M2C_FIELD(&D_801E6EF0, u8 *, 0xF0E) & 1))) {
        func_800B6490(arg0);
    }
    func_800B6564(arg0, 0x3DCCCCCD);
}
