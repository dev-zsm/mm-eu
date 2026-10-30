// FLAGS: -O2 -g3 -mips2
#include "gfxprint.h"

s32 GfxPrint_VPrintf(GfxPrint *this, const char *fmt, va_list args) {
    return vaprintf(&this->callback, fmt, args);
}
