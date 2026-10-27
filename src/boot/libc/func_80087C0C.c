// FLAGS: -O2 -g0
#include "types.h"

extern u64 __ll_mul(u64 a, u64 b);
extern u64 __ull_div(u64 a, u64 b);
extern void csleep(u64 a);

void msleep(u32 a) {
    u64 t;
    t = __ll_mul((u64)a, 0x2CB4178);
    csleep(__ull_div(t, 1000));
}
