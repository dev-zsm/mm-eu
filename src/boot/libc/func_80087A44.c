// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 func_800879D0(s32 a0, s32 a1, s32 a2);
extern s32 _Printf(void *fn, void *a1, void *a2, void *a3);

s32 sprintf(s8 *buf, s8 *fmt, ...) {
    s32 ret;

    ret = _Printf(func_800879D0, buf, fmt, (char *)&fmt + 4);
    if (ret >= 0) {
        buf[ret] = 0;
    }
    return ret;
}
