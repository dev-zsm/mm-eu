// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B75BA4(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_80B75BE8(s32, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK D_801E6EF0;

void func_800029D0(s32 arg0) {
    if ((((s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5) == 1) || (M2C_FIELD(&D_801E6EF0, u8 *, 0xF0E) & 1)) {
        func_80B75BE8(arg0, 0, 1);
        func_80B75BA4(arg0, 0, 0);
        return;
    }
    func_80B75BE8(arg0, 5, 2);
    func_80B75BA4(arg0, 1, 2);
}
