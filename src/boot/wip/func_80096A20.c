// FLAGS: -O2 -g0 -mips2
#include "types.h"
void *func_80096A20(void *arg0, s32 arg1, s32 arg2) {
    u8 *p = arg0;
    s32 n = arg2;
    s32 last = arg2;
    if (n != 0) {
        n--;
        do {
            last = n;
            *p++ = arg1;
        } while (n-- != 0);
    }
    return arg0;
}
