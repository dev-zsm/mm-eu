// FLAGS: -O2 -g0 -mips2
#include "types.h"

void *func_80096AD0(void *dst, void *src, u32 n) {
    u8 *d = dst;
    u8 *s = src;

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
