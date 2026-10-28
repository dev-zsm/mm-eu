// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(s32);                         /* extern */
M2C_UNK func_80137070(s32);                         /* extern */

void func_80002FC4(s32 arg0, M2C_UNK arg1) {
    func_80137070(arg0 + 0x148);
    func_800B680C(arg0);
}
