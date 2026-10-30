// FLAGS: -O2 -g0 -mips2
#include "printf.h"

s32 vaprintf(PrintfCallback *pfn, const char *fmt, va_list ap) {
    return _Printf(*pfn, pfn, fmt, ap);
}
