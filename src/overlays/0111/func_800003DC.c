// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_801244EC(s32);                             /* extern */

s32 func_800003DC(s32 arg0) {
    if ((func_801244EC(arg0) == 0xC) || (func_801244EC(arg0) == 0xF) || (func_801244EC(arg0) == 6)) {
        return 0;
    }
    return 1;
}
