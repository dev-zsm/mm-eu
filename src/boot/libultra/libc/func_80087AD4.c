// FLAGS: -O2 -g0 -mips2
#include "boot/printf.h"

s32 aprintf(PrintfCallback *pfn, const char *fmt, ...) {
    return vaprintf(pfn, fmt, (char *)&fmt + 4);
}
