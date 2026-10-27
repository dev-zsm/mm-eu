// FLAGS: -O2 -g0 -mips2
#include "types.h"

char *func_80096A90(char *dst, char *src) {
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
