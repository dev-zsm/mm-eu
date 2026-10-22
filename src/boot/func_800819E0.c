// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u64 __ll_mul(u64 a, u64 b);
extern u64 __ull_div(u64 a, u64 b);
extern void csleep(u64 a);

void func_800819E0(u32 a0) {
    u64 t;
    u64 u;

    t = __ll_mul(a0, 0x02CB4178);
    u = __ull_div(t, 1000);
    csleep(u);
}
