// FLAGS: -O2 -g0 -mips2
#include "libc.h"

size_t strlen(const char *s) {
    const char *p = s;

    while (*p != 0) {
        p++;
    }
    return p - s;
}
