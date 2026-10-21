// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u64 func_80088B48(u64 a, u64 b);
extern u64 func_80088A48(u64 a, u64 b);
extern void func_80087B00(u64 a);

void func_800819E0(u32 a0) {
    u64 t;
    u64 u;

    t = func_80088B48(a0, 0x02CB4178);
    u = func_80088A48(t, 1000);
    func_80087B00(u);
}
