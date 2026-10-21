// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 func_800879D0(s32 a0, s32 a1, s32 a2);
extern s32 func_8008E1F0(void *fn, void *a1, void *a2, s32 a3);

s32 func_800879F4(s8 *buf, s8 *fmt, s32 a2) {
    s32 ret;

    ret = func_8008E1F0(func_800879D0, buf, fmt, a2);
    if (ret >= 0) {
        buf[ret] = 0;
    }
    return ret;
}
