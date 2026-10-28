// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A18830(s32, s32);                    /* extern */
M2C_UNK func_80A188E4(s32, s32);                    /* extern */

void func_80000A38(s32 arg0, s32 arg1) {
    func_80A18830(arg0, arg1);
    func_80A188E4(arg0, arg1);
}
