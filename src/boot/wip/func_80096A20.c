// FLAGS: -O2 -g0 -mips2
#include "types.h"
void *func_80096A20(void *arg0, s32 arg1, s32 arg2) {
    u8 *p;
    s32 n;
    s32 v1;
    p = arg0;
    v1 = arg2;
    n = arg2;
    if (n != 0) {
        n--;
        do {
            v1 = n;
            *p = arg1;
            p++;
        } while (n-- != 0);
    }
    return arg0;
}
