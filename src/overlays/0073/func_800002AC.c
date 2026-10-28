// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80893154();                                /* extern */
M2C_UNK func_808936F0(s32);                         /* extern */
M2C_UNK func_80894DD8(s32);                         /* extern */

void func_800002AC(s32 arg0) {
    if (func_80893154() != 0) {
        func_80894DD8(arg0);
        return;
    }
    func_808936F0(arg0);
}
