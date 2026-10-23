// FLAGS: -O2 -g3
#include "types.h"

extern u32 osVirtualToPhysical(u32 a);
extern u32 D_80000308;

s32 __osPiRawStartDma(s32 a0, u32 a1, u32 a2, s32 a3) {
    volatile u32 *reg;
    u32 v;

    reg = (volatile u32 *)0xA4600010;
    v = *reg;
    while (v & 3) {
        v = *reg;
    }
    *(u32 *)0xA4600000 = osVirtualToPhysical(a2);
    *(u32 *)0xA4600004 = (D_80000308 | a1) & 0x1FFFFFFF;
    switch (a0) {
        case 0:
            *(u32 *)0xA460000C = a3 - 1;
            break;
        case 1:
            *(u32 *)0xA4600008 = a3 - 1;
            break;
        default:
            return -1;
    }
    return 0;
}
