// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8364(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800B861C(s32, u8 *, s16 *, s16 *);   /* extern */

s32 func_80000210(u8 *arg0, s32 arg1) {
    s16 sp1E;
    s16 sp1C;

    func_800B861C(arg1, arg0, &sp1E, &sp1C);
    if ((M2C_FIELD(arg0, u8 *, 0x1E2) == 0) && ((sp1E >= 0) || (sp1E < 0x140)) && ((sp1C >= 0) || (sp1C < 0xF0))) {
        func_800B8364(arg0, arg1, 0x41F00000, 0x2E);
    }
    return 1;
}
