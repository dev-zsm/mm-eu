// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(s32);                         /* extern */
M2C_UNK func_80973704(s32);                         /* extern */

void func_80000760(s32 arg0) {
    func_80973704(arg0);
    func_800B6490(arg0);
}
