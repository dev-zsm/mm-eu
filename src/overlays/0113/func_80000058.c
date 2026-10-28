// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_808D6FA0();                                /* extern */

s32 func_80000058(void) {
    if (func_808D6FA0() == 0) {
        return 0;
    }
    return 1;
}
