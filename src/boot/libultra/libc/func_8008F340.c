// FLAGS: -O2 -g0 -mips2
#include "types.h"

char *strchr(const char *s, s32 c) {
    const u8 ch = c;

    while (*s != ch) {
        if (*s == 0) {
            return 0;
        }
        s++;
    }
    return (char *)s;
}
