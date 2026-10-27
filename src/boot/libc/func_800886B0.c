// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"
extern s16 D_800977D0[];
s16 sins(u16 x) {
    s16 value;

    x >>= 4;
    if (x & 0x400) {
        value = D_800977D0[0x3FF - (x & 0x3FF)];
    } else {
        value = D_800977D0[x & 0x3FF];
    }
    if (x & 0x800) {
        return -value;
    } else {
        return value;
    }
}
