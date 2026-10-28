// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80115C38(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80831040(s32, s32, M2C_UNK);           /* extern */

void func_800124A8(s32 arg0, s32 arg1) {
    func_80115C38(8, -1);
    func_80831040(arg0, arg1, 0xFF);
}
