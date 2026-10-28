// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80AB01E4(s32);                         /* extern */
M2C_UNK func_80AB023C(s32);                         /* extern */

void func_80000170(s32 arg0, M2C_UNK arg1) {
    func_80AB01E4(arg0);
    func_80AB023C(arg0);
}
