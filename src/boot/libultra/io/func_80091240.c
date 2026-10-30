// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_cont.h"

u8 __osContAddressCrc(u16 addr) {
    u32 temp = 0;
    u32 a = addr;
    u32 mask = 0x400;
    s32 i;

    do {
        temp <<= 1;
        if (a & mask) {
            if (temp & 0x20) {
                temp ^= 0x14;
            } else {
                temp++;
            }
        } else if (temp & 0x20) {
            temp ^= 0x15;
        }
        mask >>= 1;
    } while (mask != 0);

    for (i = 0; i < 5; i++) {
        temp <<= 1;
        if (temp & 0x20) {
            temp ^= 0x15;
        }
    }
    return temp & 0x1F;
}
