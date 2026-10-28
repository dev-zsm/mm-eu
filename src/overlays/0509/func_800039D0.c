// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_6012CC0;

void func_800039D0(u8 *arg0, M2C_UNK arg1) {
    func_801377D0(arg0 + 0x160, &D_6012CC0);
    M2C_FIELD(arg0, s32 *, 0x304) = 0;
}
