// FLAGS: -O2 -g0 -mips2
#include "types.h"
void *func_80096AD0(void *arg0, void *arg1, s32 arg2) {
    u8 *d;
    u8 *s;
    s32 n;
    if (arg0 == arg1) {
        return arg0;
    }
    if (arg0 < arg1) {
        d = arg0;
        s = arg1;
        n = arg2;
        while (n != 0) {
            *d = *s;
            d++;
            s++;
            n--;
        }
    } else {
        d = (u8 *)arg0 + arg2 - 1;
        s = (u8 *)arg1 + arg2 - 1;
        n = arg2;
        while (n != 0) {
            *d = *s;
            d--;
            s--;
            n--;
        }
    }
    return arg0;
}
