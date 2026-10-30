// FLAGS: -O2 -g0 -mips2
#include "gfxprint.h"

void GfxPrint_PrintString(GfxPrint *this, const char *str) {
    while (*str != 0) {
        GfxPrint_PrintChar(this, *str++);
    }
}
