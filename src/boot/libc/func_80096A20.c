// FLAGS: -O2 -g0 -mips2
#include "types.h"

void *memset(void *s, s32 c, u32 n) {
    u8 *p = s;

    while (n--) {
        *p++ = c;
    }
    return s;
}
