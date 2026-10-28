// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(s32);                         /* extern */
s32 func_80B07C64(s32);                             /* extern */
M2C_UNK func_80B083F8(s32);                         /* extern */

void func_80000C94(s32 arg0) {
    func_80B083F8(arg0);
    if (func_80B07C64(arg0 + 0x148) == 0) {
        func_800B6490(arg0);
    }
}
