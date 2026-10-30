// FLAGS: -O2 -g0 -mips2
#include "os_internal.h"

s32 func_800879F4(char *buf, const char *fmt, va_list args) {
    s32 ret;

    ret = _Printf(func_800879D0, buf, fmt, args);
    if (ret >= 0) {
        buf[ret] = 0;
    }
    return ret;
}
