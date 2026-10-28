// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80000000(u8 *arg0, s32 arg1) {
    if (arg1 == M2C_FIELD(arg0, s32 *, 0xD94)) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0xD94) = arg1;
    M2C_FIELD(arg0, s16 *, 0xD8A) = 0;
    M2C_FIELD(arg0, s8 *, 0xD88) = 0;
    return 1;
}
