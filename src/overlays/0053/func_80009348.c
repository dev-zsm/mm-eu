// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012CAD8(s32);                         /* extern */
M2C_UNK func_8080C9E8(s32 *);                       /* extern */

void func_80009348(s32 *arg0) {
    func_8012CAD8(*arg0);
    func_8080C9E8(arg0);
}
