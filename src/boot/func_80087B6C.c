// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u64 func_80088B48(u64 a, u64 b);
extern u64 func_80088A48(u64 a, u64 b);
extern void func_80087B00(u64 x);

void func_80087B6C(u32 a0) {
    u64 t;

    t = func_80088B48((u64)a0, 3);
    t = func_80088A48(t, 0x40);
    func_80087B00(t);
}
