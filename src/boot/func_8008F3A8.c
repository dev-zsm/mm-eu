// FLAGS: -O2 -g0 -mips2
#include "types.h"
void *memcpy(void *dst, void *src, u32 n) {
    u8 *d = dst;
    u8 *s = src;
    while (n > 0) { n--; *d = *s; d++; s++; }
    return dst;
}
