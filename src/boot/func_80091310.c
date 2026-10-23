// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

u8 __osContDataCrc(u8 *data) {
    u32 i;
    u32 mask;
    u32 ret;

    ret = 0;
    for (i = 0x20; i != 0; i--) {
        for (mask = 0x80; mask != 0; mask >>= 1) {
            ret <<= 1;
            if (*data & mask) {
                if (ret & 0x100) {
                    ret ^= 0x84;
                } else {
                    ret++;
                }
            } else if (ret & 0x100) {
                ret ^= 0x85;
            }
        }
        data++;
    }
    do {
        ret <<= 1;
        if (ret & 0x100) {
            ret ^= 0x85;
        }
        i++;
    } while (i < 8);
    return ret;
}
