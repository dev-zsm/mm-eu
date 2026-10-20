// FLAGS: -O1 -g0 -mips2
#include "types.h"

void func_80080180(u32 *p, s32 n, u32 v) {
    while (n != 0) {
        n -= 4;
        *p++ = v;
    }
}
