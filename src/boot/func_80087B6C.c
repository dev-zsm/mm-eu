// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u64 __ll_mul(u64 a, u64 b);
extern u64 __ull_div(u64 a, u64 b);
extern void csleep(u64 x);

void nsleep(u32 a0) {
    u64 t;

    t = __ll_mul((u64)a0, 3);
    t = __ull_div(t, 0x40);
    csleep(t);
}
