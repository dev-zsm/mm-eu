// FLAGS: -O2 -g0 -mips2
#include "os_internal.h"

char *func_80096A90(char *dst, const char *src) {
    char *d = dst;
    char c = *src;

    while (c != 0) {
        *d = c;
        d++;
        src++;
        c = *src;
    }
    *d = 0;
    return dst;
}
