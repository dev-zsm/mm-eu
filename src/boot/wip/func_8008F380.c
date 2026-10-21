// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 func_8008F380(u8 *s) {
    u8 *p = s;

    if (*s != 0) {
        do {
            p++;
        } while (*(p + 1) != 0);
    }
    return p - s;
}
