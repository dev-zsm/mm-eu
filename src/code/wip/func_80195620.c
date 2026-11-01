// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801CE940;

s32 osAiSetNextBuffer(void *buf, u32 size) {
    u8 *bufAdjust = buf;

    if (D_801CE940) {
        bufAdjust -= 0x2000;
    }
    if ((((u32)buf + size) & 0x1FFF) == 0) {
        D_801CE940 = 1;
    } else {
        D_801CE940 = 0;
    }
    if (*(u32 *)0xA450000C & 0x80000000) {
        return -1;
    }
    *(u32 *)0xA4500000 = (u32)bufAdjust - 0x80000000;
    *(u32 *)0xA4500004 = size;
    return 0;
}
