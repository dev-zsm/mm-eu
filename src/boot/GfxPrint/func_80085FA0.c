// FLAGS: -O2 -g0 -mips2
#include "gfxprint.h"

void GfxPrint_PrintStringWithSize(GfxPrint *this, const char *str, size_t size, size_t count) {
    size_t total;
    const char *p;

    p = str;
    total = size * count;
    while (total != 0) {
        GfxPrint_PrintChar(this, *p++);
        total--;
    }
}
