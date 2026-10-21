// FLAGS: -O2 -g3
#include "types.h"

extern u32 func_8008A6E0(u32 a);

s32 func_8008C810(s32 a0, u32 a1, u32 a2, s32 a3) {
    volatile u32 *reg;
    u32 v;

    reg = (volatile u32 *)0xA4600010;
    v = *reg;
    while (v & 3) {
        v = *reg;
    }
    *(u32 *)0xA4600000 = func_8008A6E0(a2);
    *(u32 *)0xA4600004 = (*(u32 *)0x80000308 | a1) & 0x1FFFFFFF;
    if (a0 == 0) {
        *(u32 *)0xA460000C = a3 - 1;
        return 0;
    }
    if (a0 == 1) {
        *(u32 *)0xA4600008 = a3 - 1;
        return 0;
    }
    return -1;
}
