// FLAGS: -O2 -g0 -mips2
#include "types.h"

void *memcpy(void *dst, void *src, s32 n) {
    u8 *d = dst;
    u8 *s = src;
    u8 c;

    while (n--) {
        c = *s++;
        *d++ = c;
    }
    return dst;
}
