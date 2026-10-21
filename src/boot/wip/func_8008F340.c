// FLAGS: -O2 -g0 -mips2
#include "types.h"

u8 *func_8008F340(u8 *s, s32 c) {
    u8 v = *s;
    u8 *p = s;
    u8 ch = c & 0xFF;

    if (ch == v) {
        return p;
    }
    while (v != 0) {
        v = p[1];
        p++;
        if (ch == v) {
            return p;
        }
    }
    return NULL;
}
