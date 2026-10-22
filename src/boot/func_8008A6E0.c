// FLAGS: -O1 -g0
#include "types.h"

void __osProbeTLB(u32 addr);

u32 osVirtualToPhysical(u32 addr) {
    if (addr >= 0x80000000 && addr < 0xA0000000) {
        return addr & 0x1FFFFFFF;
    } else if (addr >= 0xA0000000 && addr < 0xC0000000) {
        return addr & 0x1FFFFFFF;
    }
    __osProbeTLB(addr);
}
