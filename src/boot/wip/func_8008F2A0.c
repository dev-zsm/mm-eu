// FLAGS: -O2 -g0 -mips2
#include "types.h"

u8 __osVoiceContDataCrc(u8 *data, u32 n) {
    u32 ret;
    u32 mask;
    u32 i;

    ret = 0;
    i = n;
    if (i != 0) {
        do {
            for (mask = 0x80; mask != 0; mask >>= 1) {
                u32 t = ret << 1;
                ret = t;
                if (*data & mask) {
                    if (t & 0x100) {
                        ret = t ^ 0x84;
                    } else {
                        ret++;
                    }
                } else if (ret & 0x100) {
                    ret ^= 0x85;
                }
            }
            data++;
        } while (--i != 0);
    }
    do {
        u32 t = ret << 1;
        ret = t;
        if (t & 0x100) {
            ret = t ^ 0x85;
        }
        i++;
    } while (i < 8);
    return ret;
}
