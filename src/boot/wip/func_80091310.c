// FLAGS: -O2 -g0 -mips2
// Best attempt: structure/instruction count match; scratch registers differ (ROM keeps shifted value in t6, mask in a2/a1).
#include "types.h"

u8 __osContDataCrc(u8 *data) {
    u32 ret;
    u32 mask;
    u32 i;

    ret = 0;
    for (i = 0x20; i != 0; i--) {
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
