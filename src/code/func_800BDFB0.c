// FLAGS: -O2 -g3 -mips2
#include "types.h"
u8 Actor_ApplyDamage(u8 *a0) {
    s32 v = a0[0xB8];
    s32 w = a0[0xB7];
    if (v >= w) {
        a0[0xB7] = 0;
    } else {
        a0[0xB7] = w - v;
    }
    return a0[0xB7];
}
