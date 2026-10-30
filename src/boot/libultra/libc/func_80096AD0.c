// FLAGS: -O2 -g0 -mips2
#include "libultra_libc.h"

void *func_80096AD0(void *dst, const void *src, u32 n) {
    u8 *d = dst;
    const u8 *s = src;

    if (d == s) {
        return dst;
    }
    if (d < s) {
        while (n--) {
            *d++ = *s++;
        }
    } else {
        d += n - 1;
        s += n - 1;
        while (n--) {
            *d-- = *s--;
        }
    }
    return dst;
}
