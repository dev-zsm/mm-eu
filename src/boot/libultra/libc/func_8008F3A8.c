// FLAGS: -O2 -g0 -mips2
#include "libc.h"

void *memcpy(void *dst, const void *src, size_t n) {
    u8 *d = dst;
    const u8 *s = src;

    while (n > 0) {
        n--;
        *d = *s;
        d++;
        s++;
    }
    return dst;
}
