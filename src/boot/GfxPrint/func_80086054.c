// FLAGS: -O2 -g0 -mips2
#include "boot/gfxprint.h"

void *GfxPrint_Callback(void *arg, const char *str, size_t size) {
    GfxPrint_PrintStringWithSize(arg, str, 1, size);
    return arg;
}
