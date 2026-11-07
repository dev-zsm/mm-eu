// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801E6EF0;

s32 func_80000064(s32 a0, s32 a1) {
    u8 *p = &D_801E6EF0;
    s32 ret;

    ret = (p[0xF19] & 0x80) != 0;
    if (ret == 0) {
        ret = (p[0xF0D] & 1) != 0;
    }
    return ret;
}
