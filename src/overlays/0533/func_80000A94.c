// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(s32);                         /* extern */
M2C_UNK func_80B80B24(s32);                         /* extern */

void func_80000A94(s32 arg0) {
    func_80B80B24(arg0);
    func_800B6490(arg0);
}
