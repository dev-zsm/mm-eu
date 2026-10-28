// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80830238(s32, s32);                        /* extern */
s32 func_808304A0(s32, s32);                        /* extern */

s32 func_8001AD6C(s32 arg0, s32 arg1) {
    if ((func_80830238(arg1, arg0) != 0) || (func_808304A0(arg0, arg1) != 0)) {
        return 1;
    }
    return 0;
}
