// FLAGS: -O2 -g0
#include "types.h"

extern u64 __ll_mul(u64 a, u64 b);
extern void csleep(u64 a);

void sleep(u32 a) {
    csleep(__ll_mul((u64)a, 0x2CB4178));
}
