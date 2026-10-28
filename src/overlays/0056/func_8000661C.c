// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8000661C(s32 arg0) {
    s32 temp_v0;

    temp_v0 = arg0 - 2;
    if ((temp_v0 >= 0) && (temp_v0 < 2)) {
        return temp_v0;
    }
    return -1;
}
