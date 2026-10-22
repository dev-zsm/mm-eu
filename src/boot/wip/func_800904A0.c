// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 bcmp(u8 *a0, u8 *a1, s32 a2) {
    while (a2 > 0) {
        if (*a0 != *a1) {
            return 1;
        }
        a0++;
        a1++;
        a2--;
    }
    return 0;
}
