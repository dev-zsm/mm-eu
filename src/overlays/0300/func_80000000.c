// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B2BA4(s32, M2C_UNK, M2C_UNK *);     /* extern */
M2C_UNK func_800B8C4C(s32, M2C_UNK);                /* extern */
M2C_UNK func_800FF3BC(s32, M2C_UNK, M2C_UNK *);     /* extern */
M2C_UNK func_800FF488(M2C_UNK *, M2C_UNK);          /* extern */

void func_80000000(s32 arg0, s32 arg1, s32 arg2, M2C_UNK arg3) {
    s32 pad[2];
    M2C_UNK sp1C;

    func_800FF3BC(arg2, arg3, &sp1C);
    func_800FF488(&sp1C, 0x3F000000);
    func_800B2BA4(arg0, 3, &sp1C);
    func_800B8C4C(arg1, 0x1808);
}
