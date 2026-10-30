// FLAGS: -O2 -g0 -mips2
#include "printf.h"

s32 sprintf(char *buf, const char *fmt, ...) {
    s32 ret;

    ret = _Printf(func_800879D0, buf, fmt, (char *)&fmt + 4);
    if (ret >= 0) {
        buf[ret] = 0;
    }
    return ret;
}
