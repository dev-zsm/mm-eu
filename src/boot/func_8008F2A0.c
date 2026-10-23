// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"
u8 __osVoiceContDataCrc(u8 *data, u32 bytes) {
    u32 ret = 0;
    u32 i;
    u32 mask;

    for (i = bytes; i != 0; i--) {
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
