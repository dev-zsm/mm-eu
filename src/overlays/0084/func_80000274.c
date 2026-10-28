// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E0FAC(M2C_UNK, s32, M2C_UNK);       /* extern */
M2C_UNK func_801A2E38();                            /* extern */

void func_80000274(u8 *arg0, M2C_UNK arg1) {
    func_800E0FAC(arg1, arg0 + 0x2B8, arg1);
    if (M2C_FIELD(arg0, u16 *, 0x2B6) & 0x100) {
        func_801A2E38();
    }
}
