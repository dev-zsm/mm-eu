// FLAGS: -O2 -g0
#include "types.h"
u16 __osSumcalc(u8 *p, s32 n) {
    u32 sum = 0;
    s32 i = 0;
    s32 rem = n & 3;
    if (n > 0) {
        while (i < rem) {
            sum += *p;
            p++;
            i++;
        }
        while (i < n) {
            sum += p[0];
            sum += p[1];
            sum += p[2];
            sum += p[3];
            p += 4;
            i += 4;
        }
    }
    return sum & 0xFFFF;
}
