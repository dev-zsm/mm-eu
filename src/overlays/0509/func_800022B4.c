// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800022B4(s32 arg0) {
    if ((arg0 == 1) || (arg0 == 2) || (arg0 == 3)) {
        return 1;
    }
    return 0;
}
